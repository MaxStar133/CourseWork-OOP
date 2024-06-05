#pragma once
#include <iostream>
#include "WaterTransport.h"

//����� ��� ������� ���������� � ����������
class EnginePoweredWaterTransport : 
    public WaterTransport
{
    private:
        int powerEngine;
    public:
        EnginePoweredWaterTransport();
        EnginePoweredWaterTransport(std::string name, double maxSpeed, int passengerCapacity, int powerEngine);
        void SetPowerEngine(int powerEngine);
        int GetPowerEngine();
        void Print();
        void PrintToFile(std::ofstream& outputFile);
        void ReadFromFile(std::ifstream& inFile);
        ~EnginePoweredWaterTransport() {};
};