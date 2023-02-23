#ifndef GENIE_ANALYSIS_ORIGINAL_CUTS_H
#define GENIE_ANALYSIS_ORIGINAL_CUTS_H

#include <TH3D.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TRandom.h>

#include "Fiducial.h"
#include "GenieAnalysisAuto.h"
#include "misc.h"

class FiducialWrapper {
  public:
    enum class PiPhotonId : int { Minus = -1, Photon = 0, Plus = 1 };

  private:
    Fiducial m_fiducial;

  public:
    FiducialWrapper() : m_fiducial{} {
        // Set up fiducial for 2.261Gev and carbon 12 target
        m_fiducial.InitPiMinusFit("2261");
        m_fiducial.InitEClimits();

        m_fiducial.SetConstants(2250, "12C", {{"1161", 1.161}, {"2261", 2.261}, {"4461", 4.461}});
        m_fiducial.SetFiducialCutParameters("2261");
    }

    bool electronCut(TVector3 momentum_V3) { return m_fiducial.EFiducialCut("2261", momentum_V3); }

    bool piAndPhotonCuts(TVector3 momentum_V3, PiPhotonId which_particle) {
        return m_fiducial.Pi_phot_fid_united("2261", momentum_V3, static_cast<int>(which_particle));
    }
};

// So far I'm only focusing on exactly the stuff used with the command line arguments in the README,
// specifically this means 2.261GeV beam on C12 target and more.
class GenieAnalysisOriginalCuts : public GenieAnalysisAutoTH1Fs {
  private:
    // Paths and other system stuff

    FiducialWrapper m_fiducials;

    // e2a acceptance maps
    // TODO: Move these to the constructor in some nice way, should not just be hardcoded
    const std::unique_ptr<TFile> m_el_acceptance_file{
        TFile::Open("original/e2a_maps/e2a_maps_12C_E_2_261.root", "READ")};
    const std::unique_ptr<TFile> m_p_acceptance_file{
        TFile::Open("original/e2a_maps/e2a_maps_12C_E_2_261_p.root", "READ")};
    const std::unique_ptr<TFile> m_pip_acceptance_file{
        TFile::Open("original/e2a_maps/e2a_maps_12C_E_2_261_pip.root", "READ")};
    const std::unique_ptr<TFile> m_pim_acceptance_file{
        TFile::Open("original/e2a_maps/e2a_maps_12C_E_2_261_pim.root", "READ")};

    // It seems to be necessary for I suppose performance reason? that these are found beforehand and not at each call
    // to acceptanceJoined
    const std::unique_ptr<TH3D> m_acc_el_gen, m_acc_el_acc, m_acc_p_gen, m_acc_p_acc, m_acc_pip_gen, m_acc_pip_acc,
        m_acc_pim_gen, m_acc_pim_acc;

  protected:
    // Parameters
    static constexpr double m_smearing_reso_p{0.01};   // smearing for the proton
    static constexpr double m_smearing_reso_el{0.005}; // smearing for the electrons
    static constexpr double m_smearing_reso_pi{0.007}; // smearing for pions, executive decision by Larry (28.08.19)

    // Properties of the loaded event to be set and used in passesCuts and new properties
    // electron
    TVector3 m_smeared_el_V3; // Smeared and rotated by pi
    TLorentzVector m_smeared_el_V4;
    double electron_acceptance_weight;

    // hadrons -- all of these only contain information on particles passing relevant cuts (pions need momentum above
    // 0.15 for example)
    vector<tuple<TLorentzVector, TVector3, double>>
        m_passed_pi_plus; // tuple has the smeared 4 momentum, smeared 3 momentum and the pions calculated acceptance
    vector<tuple<TLorentzVector, TVector3, double>>
        m_passed_pi_minus; // tuple has the smeared 4 momentum, smeared 3 momentum and the pions calculated acceptance
    vector<tuple<TLorentzVector, TVector3, double>>
        m_passed_photons; // tuple has the smeared 4 momentum, smeared 3 momentum and the pions calculated acceptance

    // Extensions to automatic TH1Fs
    map<string, AutoProperty> m_new_known_properties{
        {"el_smeared_phi",
         {{720, -30, 330},
          [this]() {
              double phi_deg{m_smeared_el_V3.Phi() * TMath::RadToDeg()};
              return (phi_deg < -30) ? phi_deg + 360 : phi_deg;
          }}},
        {"el_smeared_cos_theta", {{720, -1, 1}, [this]() { return m_smeared_el_V3.CosTheta(); }}},
        {"el_smeared_mag", {{720, 0, 3}, [this]() { return m_smeared_el_V3.Mag(); }}},
        {"el_acceptance", {{100, 0, 1}, [this]() { return electron_acceptance_weight; }}}};

  public:
    GenieAnalysisOriginalCuts(const char *filename, const char *output_filename, const vector<string> &stages,
                              const vector<string> &properties, const vector<string> &types,
                              const char *gst_ttree_name = "gst")
        : GenieAnalysisAutoTH1Fs(filename, output_filename, stages, properties, types, gst_ttree_name), m_fiducials{},
          m_acc_el_gen{(TH3D *)m_el_acceptance_file->Get("Generated Particles")},
          m_acc_el_acc{(TH3D *)m_el_acceptance_file->Get("Accepted Particles")},
          m_acc_p_gen{(TH3D *)m_p_acceptance_file->Get("Generated Particles")},
          m_acc_p_acc{(TH3D *)m_p_acceptance_file->Get("Accepted Particles")},
          m_acc_pip_gen{(TH3D *)m_pip_acceptance_file->Get("Generated Particles")},
          m_acc_pip_acc{(TH3D *)m_pip_acceptance_file->Get("Accepted Particles")},
          m_acc_pim_gen{(TH3D *)m_pim_acceptance_file->Get("Generated Particles")},
          m_acc_pim_acc{(TH3D *)m_pim_acceptance_file->Get("Accepted Particles")} {
        m_known_properties.insert(m_new_known_properties.begin(), m_new_known_properties.end());
    }

    Double_t passesCuts();

    double acceptanceJoined(const double &p, const double &cos_theta, double phi,
                            const std::unique_ptr<TH3D> &generated, const std::unique_ptr<TH3D> &accepted);

    double electronAcceptance(const double &p, const double &cos_theta, const double &phi) {
        return acceptanceJoined(p, cos_theta, phi, m_acc_el_gen, m_acc_el_acc);
    }

    double photonAcceptance(const double &p, const double &cos_theta, const double &phi) {
        return acceptanceJoined(p, cos_theta, phi, m_acc_p_gen, m_acc_p_acc);
    }

    double piPlusAcceptance(const double &p, const double &cos_theta, const double &phi) {
        return acceptanceJoined(p, cos_theta, phi, m_acc_pip_gen, m_acc_pip_acc);
    }

    double piMinusAcceptance(const double &p, const double &cos_theta, const double &phi) {
        return acceptanceJoined(p, cos_theta, phi, m_acc_pim_gen, m_acc_pim_acc);
    }
};

#endif
