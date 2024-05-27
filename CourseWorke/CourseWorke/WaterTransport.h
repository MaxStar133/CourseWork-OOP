#include "IWaterTransport.h"

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
    double GetMaxSpeed() const override;
    void SetPassengerCapacity(int PassengerCapacity);
    int GetPassengerCapacity() const override;
    void SetName(std::string Type);
    std::string GetName() const override;
    ~WaterTransport() {};
};

