#include "TouristBoat.h"
using namespace std;

TouristBoat::TouristBoat() {
    ticketPrice = 1000;
}
TouristBoat::TouristBoat(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, int ticketPrice) : ticketPrice(ticketPrice) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetPowerEngine(powerEngine);
};
void TouristBoat::SetTicketPrice(int ticketPrice) {
    if (ticketPrice < 0) {
        throw std::invalid_argument("Цена билета не может быть отрицательной.");
    }
    this->ticketPrice = ticketPrice;
}

int TouristBoat::GetTicketPrice() {
    return ticketPrice;
}

void TouristBoat::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
    cout << this->GetPowerEngine() << endl;
    cout << this->GetTicketPrice() << endl;
}

void TouristBoat::PrintToFile(std::ofstream& outputFile) {
    outputFile << "TOURIST_BOAT" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetTicketPrice() << std::endl;
}
void TouristBoat::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    int ticketPrice;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> ticketPrice;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetTicketPrice(ticketPrice);
}