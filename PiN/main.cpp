#include <iostream>
#include "include/Dat.h"
#include "include/Amplitudes.h"
#include "include/CrossSection.h"
#include "include/Argand.h"

using namespace std;

int main() {
    cout << "====== Protection from fools is absent. Please be careful! ======" << endl;

    Dat *dat = new Dat();
    if (dat->GetSize() == 0) {
        cerr << "****** Set the correct PATH to .dat file! ******" << endl;
        return 0;
    }

    Int_t channel = 0;
    cout << "Select channel from 1 to 8 (You could get indexes from the task)" << endl;
    cout << ">> ";
    cin >> channel;
    channel--;

    Int_t energy = 0;
    cout << "Select energy from 10 to 1500 MeV (with step = 10 MeV)" << endl;
    cout << ">> ";
    cin >> energy;
    energy /= 10;

    Int_t isoSpin = 0;
    cout << "Select isospin value: \n(1) 1/2 \n(2) 3/2" << endl;
    cout << ">> ";
    cin >> isoSpin;
    isoSpin--;

    Int_t orbAngMom = 0;
    cout << "Select orbital angular momentum from 0 to 6" << endl;
    cout << ">> ";
    cin >> orbAngMom;

    Int_t angMom = 0;
    cout << "Select angular momentum: \n(1) " << orbAngMom - 0.5 << "\n(2) " << orbAngMom + 0.5 << endl;
    cout << ">> ";
    cin >> angMom;
    angMom--;

    Amplitudes *ampl = new Amplitudes(dat);
    CrossSection *cs = new CrossSection(ampl, channel, energy);

    TGraph *difCS = cs->GetDifferentialCS();
    difCS->SetTitle("Differential cross section; #Theta; d#sigma / d#Omega, [mb / sr]");
    difCS->SetLineColor(kGreen+2);
    difCS->SetLineStyle(1);
    difCS->SetLineWidth(5);
    difCS->SetMarkerSize(0.);
    difCS->SetMarkerColor(kGreen+2);

    TGraph *intCS = cs->GetIntegralCS();
    intCS->SetTitle("Integral cross section; Energy, [MeV]; #sigma, [mb]");
    intCS->SetLineColor(kRed+2);
    intCS->SetLineStyle(1);
    intCS->SetLineWidth(5);
    intCS->SetMarkerSize(0.);
    intCS->SetMarkerColor(kRed+2);

    Argand *arg = new Argand(dat);

    TGraph *argand = arg->ArgandDiagram(orbAngMom, isoSpin, angMom);
    argand->SetTitle("Argand diagram; re F; im F");
    argand->SetLineColor(kBlue+2);
    argand->SetLineStyle(1);
    argand->SetLineWidth(3);
    argand->SetMarkerColor(kBlue+2);
    argand->SetMarkerStyle(47);
    argand->SetMarkerSize(1.2);

    TCanvas *dif = new TCanvas("Differential cross section", "Differential cross section", 1400, 1000);
    dif->cd();
    difCS->Draw();

    TCanvas *integr = new TCanvas("Integral cross section", "Integral cross section", 1400, 1000);
    integr->cd();
    intCS->Draw();

    TCanvas *arga = new TCanvas("Argand diagram", "Argand diagram", 1000, 1000);
    arga->cd();
    argand->Draw();

    TFile crossSectionFile("crossSection.root", "RECREATE");
    difCS->Write("Diff");
    intCS->Write("Int");
    argand->Write("Argand");
    crossSectionFile.Close();

    dif->SaveAs("Differential_cross_section.pdf", "q");
    integr->SaveAs("Integral_cross_section.pdf", "q");
    arga->SaveAs("Argand_diagram.pdf", "q");

    cout << "----- FINISH ----" << endl;
    return 0;
}