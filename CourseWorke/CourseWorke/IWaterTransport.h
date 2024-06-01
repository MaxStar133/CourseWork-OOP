#pragma once
#include <fstream>
#include <string>
// клас интерфейс
class IWaterTransport
{
public:
    // Виртуальная функция для получения имени объекта
    virtual std::string GetName() { return ""; };

    // Виртуальная функция для получения максимальной скорости водного транспорта
    virtual double GetMaxSpeed() { return 0; };

    // Виртуальная функция для получения количества пассажиров, которых может перевозить водный транспорт
    virtual int GetPassengerCapacity() { return 0; };

    virtual void Print() {};

    virtual void PrintToFile(std::ofstream& outputFile) {}
};