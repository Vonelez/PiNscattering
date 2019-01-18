//
// Created by admin on 2018-12-25.
//

#include "../include/Amplitudes.h"

Amplitudes::Amplitudes(Dat *dat) {
    this->dat = dat;
    l = new Legendre();
    cout << "No God, please NO! Amplitudes..." << endl;
}

Amplitudes::~Amplitudes() {

}

vector<Double_t> Amplitudes::F_I(Int_t isospin, Int_t energy, Double_t teta) {
    vector<Double_t> f_I;
    f_I.resize(2);
    Double_t re = 0, im = 0;
    Double_t reF_J1, reF_J2, imF_J1, imF_J2;

    for (int i = 0; i < 7; ++i) {
        reF_J1 = dat->GetReF(i, isospin, 0, energy);
        reF_J2 = dat->GetReF(i, isospin, 1, energy);
        imF_J1 = dat->GetImF(i, isospin, 0, energy);
        imF_J2 = dat->GetImF(i, isospin, 1, energy);

        Double_t pol = l->LegendrePol(i, teta);

        re += (i * reF_J1 + (i + 1) * reF_J2) * pol;
        im += (i * imF_J1 + (i + 1) * imF_J2) * pol;
    }

    f_I[0] = re;
    f_I[1] = im;

    return f_I;
}

vector<Double_t> Amplitudes::G_I(Int_t isospin, Int_t energy, Double_t teta, Double_t phi) {
    vector<Double_t> g_I;
    g_I.resize(2);
    Double_t re = 0, im = 0;
    Double_t reG_J1, reG_J2, imG_J1, imG_J2;

    for (int i = 0; i < 7; ++i) {
        reG_J1 = dat->GetReF(i, isospin, 0, energy);
        reG_J2 = dat->GetReF(i, isospin, 1, energy);
        imG_J1 = dat->GetImF(i, isospin, 0, energy);
        imG_J2 = dat->GetImF(i, isospin, 1, energy);
        Double_t pol = l->LegendrePolDeriv(i, teta);
        re += (reG_J2 - reG_J1) * pol;
        im += (imG_J2 - imG_J1) * pol;
    }
    Double_t x = re * Sin(teta);
    Double_t y = im * Sin(teta);

    re = x * Cos(phi) - y * Sin(phi);
    im = x * Sin(phi) + y * Cos(phi);

    g_I[0] = re;
    g_I[1] = im;

    return g_I;
}

vector<Double_t> Amplitudes::F_amplitude(Int_t energy, Double_t teta, Int_t channel) {
    vector<Double_t> f_I0 = F_I(0, energy, teta);
    vector<Double_t> f_I1 = F_I(1, energy, teta);
    vector<Double_t> fAmplitude;
    fAmplitude.resize(2);
    Double_t re = 0, im = 0;
    if (channel / 2 == 0) {
        re = f_I1[0];
        im = f_I1[1];
    }
    if (channel / 2 == 1) {
        re = 2. * f_I0[0] / 3. + f_I1[0] / 3.;
        im = 2. * f_I0[1] / 3. + f_I1[1] / 3.;
    }
    if (channel / 2 == 2) {
        re = f_I0[0] / 3. + 2. * f_I1[0] / 3.;
        im = f_I0[1] / 3. + 2. * f_I1[1] / 3.;
    }
    if (channel / 2 == 3) {
        re = Sqrt(2) * (-f_I0[0] + f_I1[0]) / 3.;
        im = Sqrt(2) * (-f_I0[1] + f_I1[1]) / 3.;
    }
    fAmplitude[0] = re;
    fAmplitude[1] = im;
    return fAmplitude;
}

vector<Double_t> Amplitudes::G_amplitude(Int_t energy, Double_t teta, Int_t channel) {
    Double_t phi = 0.0;
    vector<Double_t> g_I0 = G_I(0, energy, teta, phi);
    vector<Double_t> g_I1 = G_I(1, energy, teta, phi);
    vector<Double_t> gAmplitude;
    gAmplitude.resize(2);
    Double_t re = 0, im = 0;
    if (channel / 2 == 0) {
        re = g_I1[0];
        im = g_I1[1];
    }
    if (channel / 2 == 1) {
        re = 2. * g_I0[0] / 3. + g_I1[0] / 3.;
        im = 2. * g_I0[1] / 3. + g_I1[1] / 3.;
    }
    if (channel / 2 == 2) {
        re = g_I0[0] / 3. + 2. * g_I1[0] / 3.;
        im = g_I0[1] / 3. + 2. * g_I1[1] / 3.;
    }
    if (channel / 2 == 3) {
        re = Sqrt(2) * (-g_I0[0] + g_I1[0]) / 3.;
        im = Sqrt(2) * (-g_I0[1] + g_I1[1]) / 3.;
    }
    gAmplitude[0] = re;
    gAmplitude[1] = im;
    return gAmplitude;
}