#include "Catamaran.h"
using namespace std;

Catamaran::Catamaran() {
	numberOfPedals = 2;
}
Catamaran::Catamaran(std::string name, double maxSpeed, int passengerCapacity, int numberOfPedals) : numberOfPedals(numberOfPedals) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(maxSpeed);
};
void Catamaran::SetNumberOfPedals(int numberOfPedals) {
    if (numberOfPedals <= 0) {
        throw std::invalid_argument("Количество педалей не может быть отрицательным или равно 0.");
    }
    this->numberOfPedals = numberOfPedals;
}
int Catamaran::GetNumberOfPedals() {
	return numberOfPedals;
}

void Catamaran::Print() {
	cout << this->GetName() << endl;
	cout << this->GetMaxSpeed() << endl;
	cout << this->GetPassengerCapacity() << endl;
	cout << this->GetNumberOfPedals() << endl;
}

void Catamaran::PrintToFile(std::ofstream& outputFile) {
    outputFile << "CATAMARAN" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetNumberOfPedals() << std::endl;
}
void Catamaran::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    int numberOfPedals;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> numberOfPedals;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetNumberOfPedals(numberOfPedals);
}