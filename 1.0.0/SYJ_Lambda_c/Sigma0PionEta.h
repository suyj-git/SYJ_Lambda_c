#ifndef Sigma0PionEta_Header
#define Sigma0PionEta_Header

#include "GaudiKernel/Algorithm.h"
//you can add oher necessary header files
#include "GaudiKernel/NTuple.h"
#include "McDecayModeSvc/McDecayModeSvc.h"
#include "BestDTagSvc/BestDTagSvc.h"
#include "GaudiKernel/Algorithm.h"
#include "VertexFit/WTrackParameter.h"

//
//namespace
//
using CLHEP::HepLorentzVector;

class Sigma0PionEta:public Algorithm {
  public:
    Sigma0PionEta(const std::string& name, ISvcLocator* pSvcLocator);
    ~Sigma0PionEta();
    StatusCode initialize();
    StatusCode beginRun();   
    StatusCode execute();
    StatusCode endRun();
    StatusCode finalize();

    bool isGoodTrk(EvtRecTrackIterator itTrk, double &vz, double &vxy);
    bool isPronton(EvtRecTrackIterator itTrk);
    bool isPion (EvtRecTrackIterator itTrk);
    bool isKaon (EvtRecTrackIterator itTrk);
    bool isGoodShower(EvtRecTrack* trk);

    // Not Lambda_c !!!!
    bool isGoodLambda(RecMdcKalTrack* ppTrk, RecMdcKalTrack* pimTrk, 
                double& lmd_1chis, double& lmd_2chis, double& lmd_lchue,
                WTrackParameter &wvlmd, double& lmd_mass);
    //Notice that the first parameter is from member fuction isGoodLambda
    bool isGoodSigma0(WTrackParameter* virtual_lmd_trk, RecEmcShower* gammaShr, double& sigma0_mass,HepLorentzVector& p4_sigma0,double& sigma0_chis,HepLorentzVector& p4_sigma0_1c);

    bool isGoodEta(RecEmcShower *shr1,RecEmcShower *shr2,double& pi0_mass,HepLorentzVector& p4_pi0,double& pi0_chis,HepLorentzVector& p4_pi0_1c);

	bool    isGoodTrackForLambda(EvtRecTrack* trk);
  private:

     int m_irun;
     bool m_debug;
     bool m_use_Total_TOF;
     bool m_BestCandidate;

    double m_vr0cut;
    double m_vz0cut;
    double m_skim;
    double m_beamE;
    double m_ecms;
    double m_prob_cut;
    double m_CosThetaCut;

    double m_minEnergy;
    double m_gammaAngleCut;
    double m_gammatlCut;  
    double m_gammathCut;  
    double m_maxCosThetaBarrel;
    double m_minCosThetaEndcap;
    double m_maxCosThetaEndcap;
    double m_minEndcapEnergy;

    //NTuple::Item<int> m_idxmc;
    //NTuple::Array<int>m_pdgid;
    //NTuple::Array<int>m_motheridx;
    
//Because there are Lambda_c+ and Lambda_c- thus we make it twice( 0 for lambda_c+ and 1 for lambda_c-)
    NTuple::Tuple* m_tuple[2];   
    NTuple::Item<int> m_run[2];
    NTuple::Item<int> m_event[2];

    NTuple::Item<int>m_flag[2];
    NTuple::Item<int>m_charge[2];
    NTuple::Item<int>m_ngood[2];
    NTuple::Item<double>m_mass[2];
    NTuple::Item<double>m_ebeam[2];
    NTuple::Item<double>m_mbc[2];
    NTuple::Item<double>m_deltaE[2];
    NTuple::Item<int>m_index[2];
    NTuple::Matrix<double>m_fourmom[2];
  //  NTuple::Array<double>m_xy[2];
  //  NTuple::Array<double>m_mom[2];
  //  NTuple::Array<double>m_z[2];
    
    NTuple::Array<double> m_lambda_p4[2];
    NTuple::Item<double>  m_lambda_mass[2];
    NTuple::Item<double>  m_lambda_chis1[2];
    NTuple::Item<double>  m_lambda_lchue[2];
    
    NTuple::Item<double> m_sigma0_mass[2];
    NTuple::Item<double> m_sigma0_chis[2];
    //NTuple::Item<double>m_oa_ppi[2];
    //NTuple::Item<double>m_oa_pk[2];
    //NTuple::Item<double>m_oa_kpi[2];
    //NTuple::Item<double>m_diphi_ppi[2];
    //NTuple::Item<double>m_diphi_pk[2];
    //NTuple::Item<double>m_diphi_kpi[2];
    //NTuple::Item<double>m_phi_p[2];
    //NTuple::Item<double>m_phi_k[2];
    //NTuple::Item<double>m_phi_pi[2];
    //NTuple::Item<double>m_theta_p[2];
    //NTuple::Item<double>m_theta_k[2];
    //NTuple::Item<double>m_theta_pi[2];

    void addItem(int idx);

    HepLorentzVector getP4(RecEmcShower *gTrk, Hep3Vector origin);
  protected:

};
//add your inline methods

//

#endif//Sigma0PionEta_Header
