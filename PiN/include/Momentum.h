//
// Created by admin on 2018-12-25.
//

#ifndef PIN_MOMENTUM_H
#define PIN_MOMENTUM_H

#include <iostream>
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"

using namespace std;

class Momentum {
 public:
    Momentum();
    virtual ~Momentum();
    Double_t K_square(Int_t energy, Int_t chanel);

 private:
    Double_t mPi, mN, energy;
    Double_t Lambda(Double_t x, Double_t y, Double_t z);
    Double_t S_invariant();
};


#endif //PIN_MOMENTUM_H
