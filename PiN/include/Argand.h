//
// Created by admin on 2018-12-25.
//

#ifndef PIN_ARGAND_H
#define PIN_ARGAND_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "Dat.h"
#include "TGraph.h"

using namespace std;

class Argand {
 public:
    Argand(Dat *dat);
    virtual ~Argand();
    void SetReMax(Double_t reMax) { this->reMax = reMax; }
    void SetReMin(Double_t reMin) { this->reMin = reMin; }
    void SetImMax(Double_t imMax) { this->imMax = imMax; }
    void SetImMin(Double_t imMin) { this->imMin = imMin; }
    TGraph *ArgandDiagram(Int_t orbAngMom, Int_t isospin, Int_t angMom);
 private:
    Double_t reMax, reMin;
    Double_t imMax, imMin;
    Dat *dat;
};


#endif //PIN_ARGAND_H
