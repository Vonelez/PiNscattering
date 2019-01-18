#include "../include/CrossSection.h"

CrossSection::CrossSection(Amplitudes *ampl, Int_t channel, Int_t selectedEnergy) {
    cout << "Cross section? Seriously?!" << endl;
    mom = new Momentum();
    this->ampl = ampl;
    this->channel = channel;
    this->selectedEnergy = selectedEnergy;
    CS();
}

CrossSection::~CrossSection() {

}

void CrossSection::CS() {
    vector<Double_t> f, g;
    f.resize(2);
    g.resize(2);

    for (int k = 0; k < 2; ++k) {
        f[k] = 0;
        g[k] = 0;
    }
    diffCS = new TGraph();
    intCS = new TGraph();

    for (int j = 1; j < 150; ++j) { //energy loop
        energy[j] = j * 10;
        sigma[j] = 0;

        for (int i = 0; i < numOfTeta - 1; ++i) { //angular loop
            dSigmaPervious = 0;
            dSigmaNext = 0;
            teta[i] = 0.0;
            teta[i] = i * TMath::Pi() / (numOfTeta - 1);
            f = ampl->F_amplitude(j, teta[i], channel);
            g = ampl->G_amplitude(j, teta[i], channel);
            Double_t zzTop = (f[0] * f[0] + f[1] * f[1] + g[0] * g[0] + g[1] * g[1]) / mom->K_square(j, channel) * 1000000;
            if (j == selectedEnergy) {
                dSigma[i] = zzTop;
                if (dSigma[i] > maxDSigma) maxDSigma = dSigma[i];
            }

            dSigmaNext = TMath::Sin(teta[i]) * zzTop;
//            cout << dSigmaNext << " = dsigmaNext" << endl;

            if (i > 0) {
                sigma[j] += (dSigmaNext + dSigmaPervious) / 2 * TMath::Pi() / (numOfTeta - 1);
//                cout << "sigma "  << sigma[j] << endl;
            }
            dSigmaPervious = dSigmaNext;
        }
        sigma[j] *= 2 * TMath::Pi();
        if (sigma[j] > maxSigma) maxSigma = sigma[j];
    }

    dSigma[0] = dSigma[1];
    energy[0] = 0;
    sigma[0] = sigma[1];

    diffCS = new TGraph(numOfTeta - 1, teta, dSigma);
    intCS = new TGraph(149, energy, sigma);

}