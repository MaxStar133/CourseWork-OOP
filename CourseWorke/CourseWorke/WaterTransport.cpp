#include "WaterTransport.h"
using namespace std;

WaterTransport::WaterTransport() {
    Name = "WaterTransport";

    MaxSpeed = 70;
    PassengerCapacity = 6;
}

void WaterTransport::SetMaxSpeed(double MaxSpeed) {
    this->MaxSpeed = MaxSpeed;
}

double WaterTransport::GetMaxSpeed()   {
    return MaxSpeed;
}

void WaterTransport::SetPassengerCapacity(int PassengerCapacity) {
    this->PassengerCapacity = PassengerCapacity;
}

int WaterTransport::GetPassengerCapacity()  {
    return PassengerCapacity;
}

void WaterTransport::SetName(std::string Type) {
    this->Name = Type;
}

std::string WaterTransport::GetName()   {
    return Name;
}

void WaterTransport::Print() {
    cout << this->GetName() << endl;
    cout << this->GetMaxSpeed() << endl;
    cout << this->GetPassengerCapacity() << endl;
}

void WaterTransport::PrintToFile(std::ofstream& outputFile) {
    outputFile << "Name: " << this->GetName() << std::endl;
    outputFile << "Max Speed: " << this->GetMaxSpeed() << std::endl;
    outputFile << "Passenger Capacity: " << this->GetPassengerCapacity() << std::endl;
}