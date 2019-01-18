//
// Created by admin on 2018-12-25.
//


#include "../include/Argand.h"

Argand::Argand(Dat *dat) {
    cout << "Bonne journée, Sénor Argand" << endl;
    this->dat = dat;
}

Argand::~Argand() {

}

TGraph *Argand::ArgandDiagram(Int_t orbAngMom, Int_t isospin, Int_t angMom) {
    Double_t reF[150], imF[150];
    for (int i = 1; i < 150; ++i) {
        reF[i-1] = dat->GetReF(orbAngMom, isospin, angMom, i);
        imF[i-1] = dat->GetImF(orbAngMom, isospin, angMom, i);
    }

    TGraph *argandGraph = new TGraph(149, reF, imF);
    return argandGraph;
}