#include "Sailboat.h"
using namespace std;

Sailboat::Sailboat() {
	sailArea = 14;
}
Sailboat::Sailboat(std::string name, double maxSpeed, int passengerCapacity, int sailArea) : sailArea(sailArea) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(maxSpeed);
};
void Sailboat::SetSailArea(double sailArea) {
    if (sailArea <= 0) {
        throw std::invalid_argument("Площадь не может быть отрицательной или не может быть равна 0.");
    }
	this->sailArea = sailArea;
}

double Sailboat::GetSailArea() {
	return sailArea;
}

void Sailboat::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetSailArea() << endl;
}

void Sailboat::PrintToFile(std::ofstream& outputFile) {
    outputFile << "SAIL_BOAT" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetSailArea() << std::endl;
}
void Sailboat::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    int sailArea;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> sailArea;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetSailArea(sailArea);
}