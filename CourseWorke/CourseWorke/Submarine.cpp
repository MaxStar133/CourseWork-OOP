#include "Submarine.h"
using namespace std;
Submarine::Submarine() {
        divingDepth = 500;
    }
Submarine::Submarine(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, double divingDepth) : divingDepth(divingDepth) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetPowerEngine(powerEngine);
};

void Submarine::SetDivingDepth(double divingDepth) {
    if (divingDepth < 0) {
        throw std::invalid_argument("√лубина погружени€ не может быть отрицательной.");
    }
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

void Submarine::PrintToFile(std::ofstream& outputFile) {
    outputFile << "SUBMARINE" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetPowerEngine() << std::endl;
    outputFile << this->GetDivingDepth() << std::endl;
}
void Submarine::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    double divingDepth;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> divingDepth;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetDivingDepth(divingDepth);
}