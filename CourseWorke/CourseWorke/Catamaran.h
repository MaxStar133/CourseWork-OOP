#pragma once
#include "WaterTransport.h"
class Catamaran :
    public WaterTransport
{
private:
    int numberOfPedals;

public:
    Catamaran();
    void SetNumberOfPedals(double NumberOfPedals);
    double GetNumberOfPedals();
    void Print();
    ~Catamaran() {};
};

