//
// Created by admin on 2018-12-25.
//

#ifndef PIN_AMPLITUDES_H
#define PIN_AMPLITUDES_H

#include <iostream>
#include <vector>
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "Dat.h"
#include "Legendre.h"

using namespace std;

class Amplitudes {
 public:
    Amplitudes(Dat *dat);
    virtual ~ Amplitudes();
    vector<Double_t> F_amplitude(Int_t energy, Double_t teta, Int_t channel);
    vector<Double_t> G_amplitude(Int_t energy, Double_t teta, Int_t channel);
 private:
    Dat *dat;
    Legendre *l;
    vector<Double_t> F_I(Int_t isospin, Int_t energy, Double_t teta);
    vector<Double_t> G_I(Int_t isospin, Int_t energy, Double_t teta, Double_t phi);
};


#endif //PIN_AMPLITUDES_H
