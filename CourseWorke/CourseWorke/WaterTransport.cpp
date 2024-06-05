#include "WaterTransport.h"
using namespace std;

WaterTransport::WaterTransport() {
    name = "WaterTransport";

    maxSpeed = 70;
    passengerCapacity = 6;
}

void WaterTransport::SetMaxSpeed(double maxSpeed) {
    if (maxSpeed < 0) {
        throw std::invalid_argument("Максимальная скорость не может быть отрицательной.");
    }
    this->maxSpeed = maxSpeed;
}

double WaterTransport::GetMaxSpeed()   {
    return maxSpeed;
}

void WaterTransport::SetPassengerCapacity(int passengerCapacity) {
    if (passengerCapacity < 0) {
        throw std::invalid_argument("Вместимость пассажиров не может быть отрицательной.");
    }
    this->passengerCapacity = passengerCapacity;
}

int WaterTransport::GetPassengerCapacity()  {
    return passengerCapacity;
}

void WaterTransport::SetName(std::string type) {
    this->name = type;
}

std::string WaterTransport::GetName()   {
    return name;
}

void WaterTransport::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
}

void WaterTransport::PrintToFile(std::ofstream& outputFile) {
    outputFile << "WATER_TRANSPORT" << endl;
    outputFile  << this->GetName() << std::endl;
    outputFile  << this->GetMaxSpeed() << std::endl;
    outputFile  << this->GetPassengerCapacity() << std::endl;
}
void WaterTransport::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
}