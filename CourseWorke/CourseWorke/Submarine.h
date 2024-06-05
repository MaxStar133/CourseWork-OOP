#pragma once

#include "EnginePoweredWaterTransport.h"
class Submarine :
    public EnginePoweredWaterTransport
{
private:
    double divingDepth;

public:
    Submarine();
    Submarine(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, double divingDepth);
    void SetDivingDepth(double divingDepth);
    double GetDivingDepth();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~Submarine() {};
};

