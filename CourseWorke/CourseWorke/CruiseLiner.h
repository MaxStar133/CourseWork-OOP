#pragma once
#include "TouristBoat.h"
class CruiseLiner :
    public TouristBoat
{
private:
    int heightWaterSlides;

public:
    CruiseLiner();
    void SetHeightWaterSlides(double heightWaterSlides);
    double GetHeightWaterSlides();
    void Print();
    ~CruiseLiner() {};
};

