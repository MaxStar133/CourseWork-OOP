#include "Catamaran.h"
using namespace std;

Catamaran::Catamaran() {
	numberOfPedals = 2;
}

void Catamaran::SetNumberOfPedals(double numberOfPedals) {
	this->numberOfPedals = numberOfPedals;
}

double Catamaran::GetNumberOfPedals() {
	return numberOfPedals;
}

void Catamaran::Print() {
	cout << this->GetName() << endl;
	cout << this->GetMaxSpeed() << endl;
	cout << this->GetPassengerCapacity() << endl;
	cout << this->GetNumberOfPedals() << endl;
}