#pragma once
#include "WaterTransport.h"
class Catamaran :
    public WaterTransport
{
private:
    int numberOfPedals;

public:
    Catamaran();
    Catamaran(std::string name, double maxSpeed, int passengerCapacity, int numberOfPedals);
    void SetNumberOfPedals(double NumberOfPedals);
    double GetNumberOfPedals();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~Catamaran() {};
};

