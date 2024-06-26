#pragma once
#include "WaterTransport.h"
class Sailboat :
    public WaterTransport
{
private:
    int sailArea;

public:
    Sailboat();
    Sailboat(std::string name, double maxSpeed, int passengerCapacity, int sailArea);
    void SetSailArea(int sailArea);
    int GetSailArea();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~Sailboat() {};
};

