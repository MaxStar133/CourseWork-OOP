#include "CruiseLiner.h"
using namespace std;

CruiseLiner::CruiseLiner() {
	heightWaterSlides = 15;
}
CruiseLiner::CruiseLiner(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, int ticketPrice, int heightWaterSlides) : heightWaterSlides(heightWaterSlides) {
    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetPowerEngine(powerEngine);
    this->SetTicketPrice(ticketPrice);
};

void CruiseLiner::SetHeightWaterSlides(double heightWaterSlides) {
    if (heightWaterSlides < 0) {
        throw std::invalid_argument("¬ысота водных горок не может быть отрицательной.");
    }
    this->heightWaterSlides = heightWaterSlides;
}

double CruiseLiner::GetHeightWaterSlides() {
	return heightWaterSlides;
}

void CruiseLiner::Print() {
	cout << this->GetName() << endl;
	cout << this->GetMaxSpeed() << endl;
	cout << this->GetPassengerCapacity() << endl;
	cout << this->GetPowerEngine() << endl;
	cout << this->GetTicketPrice() << endl;
	cout << this->GetHeightWaterSlides() << endl;
}

void CruiseLiner::PrintToFile(std::ofstream& outputFile) {
    outputFile << "CRUISE_LINER" << endl;
    outputFile << this->GetName() << std::endl;
    outputFile << this->GetMaxSpeed() << std::endl;
    outputFile << this->GetPassengerCapacity() << std::endl;
    outputFile << this->GetTicketPrice() << std::endl;
    outputFile << this->GetHeightWaterSlides() << std::endl;
}
void CruiseLiner::ReadFromFile(std::ifstream& inFile) {
    string name;
    double maxSpeed;
    int passengerCapacity;
    int ticketPrice;
    int HeightWaterSlides;

    getline(inFile, name);
    inFile >> maxSpeed;
    inFile >> passengerCapacity;
    inFile >> ticketPrice;
    inFile >> HeightWaterSlides;

    this->SetName(name);
    this->SetMaxSpeed(maxSpeed);
    this->SetPassengerCapacity(passengerCapacity);
    this->SetTicketPrice(ticketPrice);
    this->SetHeightWaterSlides(HeightWaterSlides);
}