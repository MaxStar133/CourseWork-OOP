#pragma once

#include <string>
// клас интерфейс
class IWaterTransport
{
public:
    // Виртуальная функция для получения имени объекта
    virtual std::string GetName() const = 0;

    // Виртуальная функция для получения максимальной скорости водного транспорта
    virtual double GetMaxSpeed() const = 0;

    // Виртуальная функция для получения количества пассажиров, которых может перевозить водный транспорт
    virtual int GetPassengerCapacity() const = 0;
};