#pragma once

#include "EnginePoweredWaterTransport.h"
class Submarine :
    public EnginePoweredWaterTransport
{
private:
    double divingDepth;

public:
    Submarine();
    void SetDivingDepth(double divingDepth);
    double GetDivingDepth();
    void Print();
    ~Submarine() {};
};

