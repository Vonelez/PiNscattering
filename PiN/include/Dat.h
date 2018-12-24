//
// Created by Андрей Зеленов on 2018-12-24.
//

#ifndef READINGDATFILE_H
#define READINGDATFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"

using namespace std;

class Dat {
 public:
  Dat();
  virtual ~Dat();
  Double_t GetSize() { return size; };
  Double_t GetReF(Int_t L, Int_t i, Int_t j, Int_t k) { return ref[L][i][j][k]; }
  Double_t GetImF(Int_t L, Int_t i, Int_t j, Int_t k) { return imf[L][i][j][k]; }
 private:
  Double_t energy ,ReI1J1, ImI1J1, ReI1J2, ImI1J2, ReI2J1, ImI2J1, ReI2J2, ImI2J2;
  Double_t ref[7][2][2][150];
  Double_t imf[7][2][2][150];
  Int_t size;
};

#endif //READINGDATFILE_H
