#pragma once
#include "Submarine.h"
class NuclearSubmarine :
    public Submarine
{
private:
    double powerAtomicBomb; // в мегатоннах
public:
    NuclearSubmarine();
    NuclearSubmarine(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, double divingDepth, double powerAtomicBomb);
    void SetPowerAtomicBomb(double powerAtomicBomb);
    double GetPowerAtomicBomb();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~NuclearSubmarine() {};
};

