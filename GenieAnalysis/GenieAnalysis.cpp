#include "GenieAnalysis.h"

// GenieAnalysis

void GenieAnalysis::pointBranchesAtEvent() {
    m_genie_data->SetBranchAddress("iev", &m_loaded_event.iev);
    m_genie_data->SetBranchAddress("neu", &m_loaded_event.neu);
    m_genie_data->SetBranchAddress("fspl", &m_loaded_event.fspl);
    m_genie_data->SetBranchAddress("tgt", &m_loaded_event.tgt);
    m_genie_data->SetBranchAddress("Z", &m_loaded_event.Z);
    m_genie_data->SetBranchAddress("A", &m_loaded_event.A);
    m_genie_data->SetBranchAddress("hitnuc", &m_loaded_event.hitnuc);
    m_genie_data->SetBranchAddress("hitqrk", &m_loaded_event.hitqrk);
    m_genie_data->SetBranchAddress("resid", &m_loaded_event.resid);
    m_genie_data->SetBranchAddress("sea", &m_loaded_event.sea);
    m_genie_data->SetBranchAddress("qel", &m_loaded_event.qel);
    m_genie_data->SetBranchAddress("mec", &m_loaded_event.mec); // go down from here
    m_genie_data->SetBranchAddress("res", &m_loaded_event.res);
    m_genie_data->SetBranchAddress("dis", &m_loaded_event.dis);
    m_genie_data->SetBranchAddress("coh", &m_loaded_event.coh);
    m_genie_data->SetBranchAddress("dfr", &m_loaded_event.dfr);
    m_genie_data->SetBranchAddress("imd", &m_loaded_event.imd);
    m_genie_data->SetBranchAddress("imdanh", &m_loaded_event.imdanh);
    m_genie_data->SetBranchAddress("singlek", &m_loaded_event.singlek);
    m_genie_data->SetBranchAddress("nuel", &m_loaded_event.nuel);
    m_genie_data->SetBranchAddress("em", &m_loaded_event.em);
    m_genie_data->SetBranchAddress("cc", &m_loaded_event.cc);
    m_genie_data->SetBranchAddress("nc", &m_loaded_event.nc);
    m_genie_data->SetBranchAddress("charm", &m_loaded_event.charm);
    m_genie_data->SetBranchAddress("neut_code", &m_loaded_event.neut_code);
    m_genie_data->SetBranchAddress("nuance_code", &m_loaded_event.nuance_code);
    m_genie_data->SetBranchAddress("wght", &m_loaded_event.wght);
    m_genie_data->SetBranchAddress("xs", &m_loaded_event.xs);
    m_genie_data->SetBranchAddress("ys", &m_loaded_event.ys);
    m_genie_data->SetBranchAddress("ts", &m_loaded_event.ts);
    m_genie_data->SetBranchAddress("Q2s", &m_loaded_event.Q2s);
    m_genie_data->SetBranchAddress("Ws", &m_loaded_event.Ws);
    m_genie_data->SetBranchAddress("x", &m_loaded_event.x);
    m_genie_data->SetBranchAddress("y", &m_loaded_event.y);
    m_genie_data->SetBranchAddress("t", &m_loaded_event.t);
    m_genie_data->SetBranchAddress("Q2", &m_loaded_event.Q2);
    m_genie_data->SetBranchAddress("W", &m_loaded_event.W);
    m_genie_data->SetBranchAddress("EvRF", &m_loaded_event.EvRF);
    m_genie_data->SetBranchAddress("Ev", &m_loaded_event.Ev);
    m_genie_data->SetBranchAddress("pxv", &m_loaded_event.pxv);
    m_genie_data->SetBranchAddress("pyv", &m_loaded_event.pyv);
    m_genie_data->SetBranchAddress("pzv", &m_loaded_event.pzv);
    m_genie_data->SetBranchAddress("En", &m_loaded_event.En);
    m_genie_data->SetBranchAddress("pxn", &m_loaded_event.pxn);
    m_genie_data->SetBranchAddress("pyn", &m_loaded_event.pyn);
    m_genie_data->SetBranchAddress("pzn", &m_loaded_event.pzn);
    m_genie_data->SetBranchAddress("El", &m_loaded_event.El);
    m_genie_data->SetBranchAddress("pxl", &m_loaded_event.pxl);
    m_genie_data->SetBranchAddress("pyl", &m_loaded_event.pyl);
    m_genie_data->SetBranchAddress("pzl", &m_loaded_event.pzl);
    m_genie_data->SetBranchAddress("pl", &m_loaded_event.pl);
    m_genie_data->SetBranchAddress("cthl", &m_loaded_event.cthl);
    m_genie_data->SetBranchAddress("nfp", &m_loaded_event.nfp);
    m_genie_data->SetBranchAddress("nfn", &m_loaded_event.nfn);
    m_genie_data->SetBranchAddress("nfpip", &m_loaded_event.nfpip);
    m_genie_data->SetBranchAddress("nfpim", &m_loaded_event.nfpim);
    m_genie_data->SetBranchAddress("nfpi0", &m_loaded_event.nfpi0);
    m_genie_data->SetBranchAddress("nfkp", &m_loaded_event.nfkp);
    m_genie_data->SetBranchAddress("nfkm", &m_loaded_event.nfkm);
    m_genie_data->SetBranchAddress("nfk0", &m_loaded_event.nfk0);
    m_genie_data->SetBranchAddress("nfem", &m_loaded_event.nfem);
    m_genie_data->SetBranchAddress("nfother", &m_loaded_event.nfother);
    m_genie_data->SetBranchAddress("nip", &m_loaded_event.nip);
    m_genie_data->SetBranchAddress("nin", &m_loaded_event.nin);
    m_genie_data->SetBranchAddress("nipip", &m_loaded_event.nipip);
    m_genie_data->SetBranchAddress("nipim", &m_loaded_event.nipim);
    m_genie_data->SetBranchAddress("nipi0", &m_loaded_event.nipi0);
    m_genie_data->SetBranchAddress("nikp", &m_loaded_event.nikp);
    m_genie_data->SetBranchAddress("nikm", &m_loaded_event.nikm);
    m_genie_data->SetBranchAddress("nik0", &m_loaded_event.nik0);
    m_genie_data->SetBranchAddress("niem", &m_loaded_event.niem);
    m_genie_data->SetBranchAddress("niother", &m_loaded_event.niother);
    m_genie_data->SetBranchAddress("ni", &m_loaded_event.ni);
    m_genie_data->SetBranchAddress("pdgi", m_loaded_event.pdgi);
    m_genie_data->SetBranchAddress("resc", m_loaded_event.resc);
    m_genie_data->SetBranchAddress("Ei", m_loaded_event.Ei);
    m_genie_data->SetBranchAddress("pxi", m_loaded_event.pxi);
    m_genie_data->SetBranchAddress("pyi", m_loaded_event.pyi);
    m_genie_data->SetBranchAddress("pzi", m_loaded_event.pzi);
    m_genie_data->SetBranchAddress("nf", &m_loaded_event.nf);
    m_genie_data->SetBranchAddress("pdgf", m_loaded_event.pdgf);
    m_genie_data->SetBranchAddress("Ef", m_loaded_event.Ef);
    m_genie_data->SetBranchAddress("pxf", m_loaded_event.pxf);
    m_genie_data->SetBranchAddress("pyf", m_loaded_event.pyf);
    m_genie_data->SetBranchAddress("pzf", m_loaded_event.pzf);
    m_genie_data->SetBranchAddress("pf", m_loaded_event.pf);
    m_genie_data->SetBranchAddress("cthf", m_loaded_event.cthf);
    m_genie_data->SetBranchAddress("vtxx", &m_loaded_event.vtxx);
    m_genie_data->SetBranchAddress("vtxy", &m_loaded_event.vtxy);
    m_genie_data->SetBranchAddress("vtxz", &m_loaded_event.vtxz);
    m_genie_data->SetBranchAddress("vtxt", &m_loaded_event.vtxt);
    m_genie_data->SetBranchAddress("sumKEf", &m_loaded_event.sumKEf);
    m_genie_data->SetBranchAddress("calresp0", &m_loaded_event.calresp0);
}

// GenieAnalysisAutoTH1Fs

bool GenieAnalysisAutoTH1Fs::isObservable(const string &observable, const GenieEvent &ge) {
    if (observable == "QE") {
        return ge.qel;
    } else if (observable == "RES") {
        return ge.res;
    } else if (observable == "DIS") {
        return ge.dis;
    } else {
        // TODO: improve errors
        throw -1;
    }
}

bool GenieAnalysisAutoTH1Fs::getProperty(const string &property, const GenieEvent &ge) {
    if (property == "W") {
        return ge.W;
    } else {
        // TODO: improve errors
        throw -1;
    }
}
