#pragma once
#include "EnginePoweredWaterTransport.h"
class TouristBoat :
    public EnginePoweredWaterTransport
{
private:
    int ticketPrice;

public:
    TouristBoat();
    TouristBoat(std::string name, double maxSpeed, int passengerCapacity, int powerEngine, int ticketPrice);
    void SetTicketPrice(int ticketPrice);
    int GetTicketPrice();
    void Print();
    void PrintToFile(std::ofstream& outputFile);
    void ReadFromFile(std::ifstream& inFile);
    ~TouristBoat() {};
};

