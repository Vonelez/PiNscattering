#include <iostream>
#include "include/Dat.h"

using namespace std;
int main() {

    cout << "Protection from fools is absent. Please be careful!" << endl;

    Dat* newDat = new Dat();
    cout << newDat->GetSize() << endl;

    Int_t chanel;
    cout << "Select chanel from 1 to 8 (You could get indexes from the task)" << endl;
    cout << ">> ";
    cin >> chanel;
    chanel--;

    Int_t energy;
    cout << "Select energy from 10 to 1500 MeV (with step = 10 MeV)" << endl;
    cout << ">> ";
    cin >> energy;
    energy /= 10;

    Int_t isoSpin;
    cout << "Select isospin value: \n(1) 1/2 \n(2) 3/2" << endl;
    cout << ">> ";
    cin >> isoSpin;
    isoSpin--;

    Int_t orbAngMom;
    cout << "Select orbital angular momentum from 0 to 6" << endl;
    cout << ">> ";
    cin >> orbAngMom;

    Int_t angMom;
    cout << "Select angular momentum: \n(1) " << orbAngMom - 0.5 << "\n(2) " << orbAngMom + 0.5 << endl;
    cout << ">> ";
    cin >> angMom;
    angMom--;


    return 0;
}