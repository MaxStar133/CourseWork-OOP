#pragma once
#include "Submarine.h"
class NuclearSubmarine :
    public Submarine
{
private:
    double powerAtomicBomb; // в мегатоннах
public:
    NuclearSubmarine();
    void SetPowerAtomicBomb(double powerAtomicBomb);
    double GetPowerAtomicBomb();
    void Print();
    ~NuclearSubmarine() {};
};

