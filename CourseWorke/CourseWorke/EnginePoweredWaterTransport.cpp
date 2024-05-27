#include "EnginePoweredWaterTransport.h"
using namespace std;

EnginePoweredWaterTransport::EnginePoweredWaterTransport() {
    PowerEngine = 300;
}

void EnginePoweredWaterTransport::SetPowerEngine(int PowerEngine) {
    this->PowerEngine = PowerEngine;
}

int EnginePoweredWaterTransport::GetPowerEngine() {
    return PowerEngine;
}

void EnginePoweredWaterTransport::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetPowerEngine() << endl;
}