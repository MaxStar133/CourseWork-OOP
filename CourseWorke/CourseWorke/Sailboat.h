#pragma once
#include "WaterTransport.h"
class Sailboat :
    public WaterTransport
{
private:
    int sailArea;

public:
    Sailboat();
    void SetSailArea(double sailArea);
    double GetSailArea();
    void Print();
    ~Sailboat() {};
};

