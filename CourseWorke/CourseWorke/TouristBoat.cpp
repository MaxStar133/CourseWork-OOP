#include "TouristBoat.h"
using namespace std;

TouristBoat::TouristBoat() {
    ticketPrice = 1000;
}

void TouristBoat::SetTicketPrice(int ticketPrice) {
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