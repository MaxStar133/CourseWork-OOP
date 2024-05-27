#include "Sailboat.h"
using namespace std;

Sailboat::Sailboat() {
	sailArea = 14;
}

void Sailboat::SetSailArea(double sailArea) {
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