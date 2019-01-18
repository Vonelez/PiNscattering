//
// Created by admin on 2018-12-25.
//

#ifndef PIN_CROSSSECTION_H
#define PIN_CROSSSECTION_H

#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TGraph.h"
#include "TMath.h"
#include "TCanvas.h"
#include "Amplitudes.h"
#include "Momentum.h"

class CrossSection {
 public:
    CrossSection(Amplitudes *ampl, Int_t channel, Int_t selectedEnergy);
    virtual ~CrossSection();
    TGraph *GetDifferentialCS() { return diffCS; }
    TGraph *GetIntegralCS() { return  intCS; }

 private:
    Amplitudes *ampl;
    Int_t channel, selectedEnergy;
    void CS();
    Momentum *mom;
    static const Int_t numOfTeta = 180;
    Double_t dSigma[numOfTeta], sigma[150], teta[numOfTeta], energy[150];
    Double_t dSigmaPervious, dSigmaNext;
    Double_t maxDSigma, maxSigma;
    TGraph *diffCS, *intCS;
};


#endif //PIN_CROSSSECTION_H
