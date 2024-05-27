#include "NuclearSubmarine.h"
using namespace std;

NuclearSubmarine::NuclearSubmarine() {
    powerAtomicBomb = 50;
}

void NuclearSubmarine::SetPowerAtomicBomb(double powerAtomicBomb) {
    this->powerAtomicBomb = powerAtomicBomb;
}

double NuclearSubmarine::GetPowerAtomicBomb() {
    return powerAtomicBomb;
}

void NuclearSubmarine::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetPowerEngine() << endl;
    cout << this->GetDivingDepth() << endl;
    cout << this->GetPowerAtomicBomb() << endl;
}