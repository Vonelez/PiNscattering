//
// Created by Андрей Зеленов on 2018-12-24.
//

#include "../include/Legendre.h"


Legendre::Legendre() {
    std::cout << "Legendre time!" << std::endl;
}

Legendre::~Legendre() {

}

using namespace TMath;

Double_t Legendre::LegendrePol(Int_t n, Double_t teta) {
    Double_t x = Cos(teta);
    if(n == 0) return 1;
    else if(n == 1) return x;
    else return (LegendrePol(n - 1, teta) * x * (2 * n - 1) / (n)) - (LegendrePol(n - 2, teta) * (n - 1) / (n));
}

Double_t Legendre::LegendrePolDeriv(Int_t n, Double_t teta) {
    Double_t x = Cos(teta);
    return (n / (1 - x * x)) * (LegendrePol(n - 1, teta) - x * LegendrePol(n, teta));
}