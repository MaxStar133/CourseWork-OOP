#pragma once
#include "EnginePoweredWaterTransport.h"
class TouristBoat :
    public EnginePoweredWaterTransport
{
private:
    int ticketPrice;

public:
    TouristBoat();
    void SetTicketPrice(int ticketPrice);
    int GetTicketPrice();
    void Print();
    ~TouristBoat() {};
};

