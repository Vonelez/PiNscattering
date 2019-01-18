//
// Created by admin on 2018-12-25.
//

#include "../include/Momentum.h"

Momentum::Momentum() {
    cout << "Uno momentum..." << endl;
}

Momentum::~Momentum() {

}

Double_t Momentum::K_square(Int_t energy, Int_t chanel) {
    this->energy = (Double_t)energy * 10;
    if (chanel == 4 || chanel == 5) {
        mPi = 135;
    } else {
        mPi = 139.6;
    }

    if (chanel % 2 == 0) {
        mN = 938.27;
    } else {
        mN = 939.5;
    }

    Double_t s = S_invariant();

    return Lambda(s, mPi * mPi, mN * mN) / (4 * s);
}

Double_t Momentum::S_invariant() {
    return (mPi + mN) * (mPi + mN) + 2 * mN * energy;
}

Double_t Momentum::Lambda(Double_t x, Double_t y, Double_t z) {
    return (x - y - z) * (x - y - z) - 4 * y * z;
}

