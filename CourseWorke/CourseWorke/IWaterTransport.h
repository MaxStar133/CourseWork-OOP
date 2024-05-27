#pragma once

#include <string>
// ���� ���������
class IWaterTransport
{
public:
    // ����������� ������� ��� ��������� ����� �������
    virtual std::string GetName() const = 0;

    // ����������� ������� ��� ��������� ������������ �������� ������� ����������
    virtual double GetMaxSpeed() const = 0;

    // ����������� ������� ��� ��������� ���������� ����������, ������� ����� ���������� ������ ���������
    virtual int GetPassengerCapacity() const = 0;
};