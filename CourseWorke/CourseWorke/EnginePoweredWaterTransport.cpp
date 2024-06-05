#include "EnginePoweredWaterTransport.h"
using namespace std;

EnginePoweredWaterTransport::EnginePoweredWaterTransport() {
    powerEngine = 300;
}
EnginePoweredWaterTransport::EnginePoweredWaterTransport(std::string name, double maxSpeed, int passengerCapacity, int powerEngine) : powerEngine(powerEngine) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
};
void EnginePoweredWaterTransport::SetPowerEngine(int powerEngine) {
    if (powerEngine < 0) {
        throw std::invalid_argument("Мощность двигателя не может быть отрицательной.");
    }
    this->powerEngine = powerEngine;
}

int EnginePoweredWaterTransport::GetPowerEngine() {
    return powerEngine;
}

void EnginePoweredWaterTransport::Print()  {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetPowerEngine() << endl;
}

void EnginePoweredWaterTransport::PrintToFile(ofstream& outputFile) {
    outputFile << "ENGINE_POWERED_WATER_TRANSPORT" << endl;
    outputFile << this->GetName() << endl;
    outputFile <<  this->GetMaxSpeed() << endl;
    outputFile <<  this->GetPassengerCapacity() << endl;
    outputFile <<  this->GetPowerEngine() << endl;
}

void EnginePoweredWaterTransport::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    int powerEngine;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> powerEngine;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetPowerEngine(powerEngine);
}