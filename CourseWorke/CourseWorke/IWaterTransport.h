#pragma once
#include <fstream>
#include <string>
// клас интерфейс
class IWaterTransport
{
public:
 
    virtual std::string GetName() { return ""; };

    virtual double GetMaxSpeed() { return 0; };

    virtual int GetPassengerCapacity() { return 0; };

    virtual void Print() {};

    virtual void PrintToFile(std::ofstream& outputFile) {}

    virtual void ReadFromFile(std::ifstream& inFile) {}
};