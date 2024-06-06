#pragma once
#include "TouristBoat.h"
class CruiseLiner :
    public TouristBoat
{
private:
    int heightWaterSlides;

public:
    CruiseLiner();
    CruiseLiner(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, int ticketPrice, int heightWaterSlides);
    void SetHeightWaterSlides(int heightWaterSlides);
    int GetHeightWaterSlides();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~CruiseLiner() {};
};

