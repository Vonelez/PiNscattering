//
// Created by Андрей Зеленов on 2018-12-24.
//

#ifndef PIN_LEGENDRE_H
#define PIN_LEGENDRE_H

#include "TMath.h"
#include <iostream>
class Legendre {
 public:
  Legendre();
  virtual ~Legendre();
  virtual Double_t LegendrePol(Int_t n, Double_t teta);
  virtual Double_t LegendrePolDeriv(Int_t n, Double_t teta);
};

#endif //PIN_LEGENDRE_H
