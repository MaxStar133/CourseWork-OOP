#include "IWaterTransport.h"
#include <iostream>
#pragma once

// базовый класс
class WaterTransport :
public IWaterTransport
{
private:
    double MaxSpeed;
    int PassengerCapacity;
    std::string Name;
public:
    WaterTransport();
    void SetMaxSpeed(double MaxSpeed);
    double GetMaxSpeed() override;
    void SetPassengerCapacity(int PassengerCapacity);
    int GetPassengerCapacity() override;
    void SetName(std::string Type);
    std::string GetName() override;
    void Print() override;
    void PrintToFile(std::ofstream& outputFile)  override;
    ~WaterTransport() {};
};

