#include "CruiseLiner.h"
using namespace std;

CruiseLiner::CruiseLiner() {
	heightWaterSlides = 15;
}

void CruiseLiner::SetHeightWaterSlides(double heightWaterSlides) {
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