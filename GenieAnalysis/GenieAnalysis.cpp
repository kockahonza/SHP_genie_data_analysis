#include "GenieAnalysis.h"

void GenieAnalysis::pointBranchesAtEvent() {
    m_genie_data->SetBranchAddress("iev", &m_ge.iev);
    m_genie_data->SetBranchAddress("neu", &m_ge.neu);
    m_genie_data->SetBranchAddress("fspl", &m_ge.fspl);
    m_genie_data->SetBranchAddress("tgt", &m_ge.tgt);
    m_genie_data->SetBranchAddress("Z", &m_ge.Z);
    m_genie_data->SetBranchAddress("A", &m_ge.A);
    m_genie_data->SetBranchAddress("hitnuc", &m_ge.hitnuc);
    m_genie_data->SetBranchAddress("hitqrk", &m_ge.hitqrk);
    m_genie_data->SetBranchAddress("resid", &m_ge.resid);
    m_genie_data->SetBranchAddress("sea", &m_ge.sea);
    m_genie_data->SetBranchAddress("qel", &m_ge.qel);
    m_genie_data->SetBranchAddress("mec", &m_ge.mec); // go down from here
    m_genie_data->SetBranchAddress("res", &m_ge.res);
    m_genie_data->SetBranchAddress("dis", &m_ge.dis);
    m_genie_data->SetBranchAddress("coh", &m_ge.coh);
    m_genie_data->SetBranchAddress("dfr", &m_ge.dfr);
    m_genie_data->SetBranchAddress("imd", &m_ge.imd);
    m_genie_data->SetBranchAddress("imdanh", &m_ge.imdanh);
    m_genie_data->SetBranchAddress("singlek", &m_ge.singlek);
    m_genie_data->SetBranchAddress("nuel", &m_ge.nuel);
    m_genie_data->SetBranchAddress("em", &m_ge.em);
    m_genie_data->SetBranchAddress("cc", &m_ge.cc);
    m_genie_data->SetBranchAddress("nc", &m_ge.nc);
    m_genie_data->SetBranchAddress("charm", &m_ge.charm);
    m_genie_data->SetBranchAddress("neut_code", &m_ge.neut_code);
    m_genie_data->SetBranchAddress("nuance_code", &m_ge.nuance_code);
    m_genie_data->SetBranchAddress("wght", &m_ge.wght);
    m_genie_data->SetBranchAddress("xs", &m_ge.xs);
    m_genie_data->SetBranchAddress("ys", &m_ge.ys);
    m_genie_data->SetBranchAddress("ts", &m_ge.ts);
    m_genie_data->SetBranchAddress("Q2s", &m_ge.Q2s);
    m_genie_data->SetBranchAddress("Ws", &m_ge.Ws);
    m_genie_data->SetBranchAddress("x", &m_ge.x);
    m_genie_data->SetBranchAddress("y", &m_ge.y);
    m_genie_data->SetBranchAddress("t", &m_ge.t);
    m_genie_data->SetBranchAddress("Q2", &m_ge.Q2);
    m_genie_data->SetBranchAddress("W", &m_ge.W);
    m_genie_data->SetBranchAddress("EvRF", &m_ge.EvRF);
    m_genie_data->SetBranchAddress("Ev", &m_ge.Ev);
    m_genie_data->SetBranchAddress("pxv", &m_ge.pxv);
    m_genie_data->SetBranchAddress("pyv", &m_ge.pyv);
    m_genie_data->SetBranchAddress("pzv", &m_ge.pzv);
    m_genie_data->SetBranchAddress("En", &m_ge.En);
    m_genie_data->SetBranchAddress("pxn", &m_ge.pxn);
    m_genie_data->SetBranchAddress("pyn", &m_ge.pyn);
    m_genie_data->SetBranchAddress("pzn", &m_ge.pzn);
    m_genie_data->SetBranchAddress("El", &m_ge.El);
    m_genie_data->SetBranchAddress("pxl", &m_ge.pxl);
    m_genie_data->SetBranchAddress("pyl", &m_ge.pyl);
    m_genie_data->SetBranchAddress("pzl", &m_ge.pzl);
    m_genie_data->SetBranchAddress("pl", &m_ge.pl);
    m_genie_data->SetBranchAddress("cthl", &m_ge.cthl);
    m_genie_data->SetBranchAddress("nfp", &m_ge.nfp);
    m_genie_data->SetBranchAddress("nfn", &m_ge.nfn);
    m_genie_data->SetBranchAddress("nfpip", &m_ge.nfpip);
    m_genie_data->SetBranchAddress("nfpim", &m_ge.nfpim);
    m_genie_data->SetBranchAddress("nfpi0", &m_ge.nfpi0);
    m_genie_data->SetBranchAddress("nfkp", &m_ge.nfkp);
    m_genie_data->SetBranchAddress("nfkm", &m_ge.nfkm);
    m_genie_data->SetBranchAddress("nfk0", &m_ge.nfk0);
    m_genie_data->SetBranchAddress("nfem", &m_ge.nfem);
    m_genie_data->SetBranchAddress("nfother", &m_ge.nfother);
    m_genie_data->SetBranchAddress("nip", &m_ge.nip);
    m_genie_data->SetBranchAddress("nin", &m_ge.nin);
    m_genie_data->SetBranchAddress("nipip", &m_ge.nipip);
    m_genie_data->SetBranchAddress("nipim", &m_ge.nipim);
    m_genie_data->SetBranchAddress("nipi0", &m_ge.nipi0);
    m_genie_data->SetBranchAddress("nikp", &m_ge.nikp);
    m_genie_data->SetBranchAddress("nikm", &m_ge.nikm);
    m_genie_data->SetBranchAddress("nik0", &m_ge.nik0);
    m_genie_data->SetBranchAddress("niem", &m_ge.niem);
    m_genie_data->SetBranchAddress("niother", &m_ge.niother);
    m_genie_data->SetBranchAddress("ni", &m_ge.ni);
    m_genie_data->SetBranchAddress("pdgi", m_ge.pdgi);
    m_genie_data->SetBranchAddress("resc", m_ge.resc);
    m_genie_data->SetBranchAddress("Ei", m_ge.Ei);
    m_genie_data->SetBranchAddress("pxi", m_ge.pxi);
    m_genie_data->SetBranchAddress("pyi", m_ge.pyi);
    m_genie_data->SetBranchAddress("pzi", m_ge.pzi);
    m_genie_data->SetBranchAddress("nf", &m_ge.nf);
    m_genie_data->SetBranchAddress("pdgf", m_ge.pdgf);
    m_genie_data->SetBranchAddress("Ef", m_ge.Ef);
    m_genie_data->SetBranchAddress("pxf", m_ge.pxf);
    m_genie_data->SetBranchAddress("pyf", m_ge.pyf);
    m_genie_data->SetBranchAddress("pzf", m_ge.pzf);
    m_genie_data->SetBranchAddress("pf", m_ge.pf);
    m_genie_data->SetBranchAddress("cthf", m_ge.cthf);
    m_genie_data->SetBranchAddress("vtxx", &m_ge.vtxx);
    m_genie_data->SetBranchAddress("vtxy", &m_ge.vtxy);
    m_genie_data->SetBranchAddress("vtxz", &m_ge.vtxz);
    m_genie_data->SetBranchAddress("vtxt", &m_ge.vtxt);
    m_genie_data->SetBranchAddress("sumKEf", &m_ge.sumKEf);
    m_genie_data->SetBranchAddress("calresp0", &m_ge.calresp0);
}
