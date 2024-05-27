#include "WaterTransport.h"

WaterTransport::WaterTransport() {
    Name = "WaterTransport";

    MaxSpeed = 70;
    PassengerCapacity = 6;
}

void WaterTransport::SetMaxSpeed(double MaxSpeed) {
    this->MaxSpeed = MaxSpeed;
}

double WaterTransport::GetMaxSpeed() const  {
    return MaxSpeed;
}

void WaterTransport::SetPassengerCapacity(int PassengerCapacity) {
    this->PassengerCapacity = PassengerCapacity;
}

int WaterTransport::GetPassengerCapacity() const  {
    return PassengerCapacity;
}

void WaterTransport::SetName(std::string Type) {
    this->Name = Type;
}

std::string WaterTransport::GetName() const  {
    return Name;
}