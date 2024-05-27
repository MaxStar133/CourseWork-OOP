#pragma once
#include <iostream>
#include "WaterTransport.h"

//����� ��� ������� ���������� � ����������
class EnginePoweredWaterTransport :
    public WaterTransport
{
    private:
        int PowerEngine;
    public:
        EnginePoweredWaterTransport();
        void SetPowerEngine(int PowerEngine);
        int GetPowerEngine();
        void Print();
        ~EnginePoweredWaterTransport() {};
};