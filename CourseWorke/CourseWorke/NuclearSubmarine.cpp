#include "NuclearSubmarine.h"
using namespace std;

NuclearSubmarine::NuclearSubmarine() {
    powerAtomicBomb = 50;
}
NuclearSubmarine::NuclearSubmarine(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, double divingDepth, double powerAtomicBomb) : powerAtomicBomb(powerAtomicBomb) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetPowerEngine(powerEngine);
    this->SetDivingDepth(divingDepth);
};

void NuclearSubmarine::SetPowerAtomicBomb(double powerAtomicBomb) {
    if (powerAtomicBomb < 0) {
        throw std::invalid_argument("Мощность атомной бомбы не может быть отрицательной.");
    }
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

void NuclearSubmarine::PrintToFile(std::ofstream& outputFile) {
    outputFile << "NUCLEAR_SUBMARINE" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetPowerEngine() << std::endl;
    outputFile << this->GetDivingDepth() << std::endl;
    outputFile << this->GetPowerAtomicBomb() << std::endl;
}
void NuclearSubmarine::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    double divingDepth;
    double powerAtomic;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> divingDepth;
    inFile >> powerAtomic;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetDivingDepth(divingDepth);
    this->SetPowerAtomicBomb(powerAtomic);
}