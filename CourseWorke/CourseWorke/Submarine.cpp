#include "Submarine.h"
using namespace std;
Submarine::Submarine() {
        divingDepth = 500;
    }

void Submarine::SetDivingDepth(double divingDepth) {
    this->divingDepth = divingDepth;
}

double Submarine::GetDivingDepth() {
    return divingDepth;
}

void Submarine::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetPowerEngine() << endl;
    cout << this->GetDivingDepth() << endl;
}