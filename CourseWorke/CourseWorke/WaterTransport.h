#include "IWaterTransport.h"
#include <iostream>
#pragma once

// базовый класс
class WaterTransport :
public IWaterTransport
{
private:
    double maxSpeed;
    int passengerCapacity;
    std::string name;
public:
    WaterTransport();
    WaterTransport(std::string name, double maxSpeed, int passengerCapacity) : name(name), maxSpeed(maxSpeed), passengerCapacity(passengerCapacity) {};
    void SetMaxSpeed(double maxSpeed);
    double GetMaxSpeed() override;
    void SetPassengerCapacity(int passengerCapacity);
    int GetPassengerCapacity() override;
    void SetName(std::string type);
    std::string GetName() override;
    void Print() override;
    void PrintToFile(std::ofstream& outputFile)  override;
    void ReadFromFile(std::ifstream& inFile) override;
    ~WaterTransport() {};
};

