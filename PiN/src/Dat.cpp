//
// Created by Андрей Зеленов on 2018-12-24.
//


#include "../include/Dat.h"

Dat::Dat() {
    cout << "Lets reed the fucking FILE!" << endl;
    string line;
    char fileName[] = "PARTWPIN.DAT";
    ifstream in(fileName);
    Int_t i = 1;
    Int_t l_dat = 0;
    size = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            istringstream iss(line);
            iss >> energy >> ReI1J1 >> ImI1J1 >> ReI1J2 >> ImI1J2 >> ReI2J1 >> ImI2J1 >> ReI2J2 >> ImI2J2;
            if (energy == 0) continue;
            size++;
            ref[l_dat][0][0][i] = ReI1J1;
            imf[l_dat][0][0][i] = ImI1J1;
            ref[l_dat][0][1][i] = ReI1J2;
            imf[l_dat][0][1][i] = ImI1J2;
            ref[l_dat][1][0][i] = ReI2J1;
            imf[l_dat][1][0][i] = ImI2J1;
            ref[l_dat][1][1][i] = ReI2J2;
            imf[l_dat][1][1][i] = ImI2J2;
            i++;
            if (energy == 1500) {
                i = 0;
                l_dat++;
            }
        }
    }
    in.close();
}

Dat::~Dat() {

}