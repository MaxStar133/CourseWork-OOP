#include <iostream>
#include "MyVector.h"
#include "WaterTransport.h"
#include "EnginePoweredWaterTransport.h"
#include "TmpQueue.h"
#include "IWaterTransport.h"
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, MyVector<T*>& vec) {
    for (size_t i = 0; i < vec.Size(); ++i) {
        vec.At(i)->Print();
        os << endl;
    }
    return os;
}


// Предикаты для сортировки и поиска

int main() {
    MyVector<WaterTransport*> fleet;
    TmpQueue<IWaterTransport> queue;

    WaterTransport* boat1 = new WaterTransport();
    boat1->SetName("Boat 1");
    boat1->SetMaxSpeed(1);
    boat1->SetPassengerCapacity(10);

    EnginePoweredWaterTransport* boat2 = new EnginePoweredWaterTransport();
    boat2->SetName("Boat 2");
    boat2->SetMaxSpeed(10);
    boat2->SetPassengerCapacity(20);
    boat2->SetPowerEngine(500);

    EnginePoweredWaterTransport* boat3 = new EnginePoweredWaterTransport();
    boat3->SetName("Boat 3");
    boat3->SetMaxSpeed(40);
    boat3->SetPassengerCapacity(20);
    boat3->SetPowerEngine(500);

    EnginePoweredWaterTransport* boat4 = new EnginePoweredWaterTransport();
    boat4->SetName("Boat 4");
    boat4->SetMaxSpeed(40);
    boat4->SetPassengerCapacity(20);
    boat4->SetPowerEngine(500);

    fleet.Push_back(boat1);
    fleet.Push_back(boat2);
    fleet.Push_back(boat3);
    fleet.Push_back(boat4);

    fleet.OutputToFile("fleet_data.txt");


    queue.enqueue(boat1);
    queue.enqueue(boat2);

    for (size_t i = 0; i < fleet.Size(); ++i) {
        fleet.At(i)->Print();
    }

    fleet.Sort([](WaterTransport* a, WaterTransport* b) {
        return a->GetMaxSpeed() < b->GetMaxSpeed();
        });

    cout << "\nSorted fleet by max speed:\n";
    for (size_t i = 0; i < fleet.Size(); ++i) {
        fleet.At(i)->Print();
    }

    // Find all boats with max speed between 0 and 10
    auto result = fleet.FindInRange([](WaterTransport* boat) {
        return boat->GetMaxSpeed() >= 0 && boat->GetMaxSpeed() <= 10;
        });

    cout << "\nBoats with max speed between 0 and 10:\n";
    for (const auto& boat : result) {
        boat->Print();
    }
    cout << endl;
    cout << endl;

    cout << fleet << endl;

    cout << "\nQueue\n";
    while (!queue.isEmpty()) {
        IWaterTransport* item = queue.dequeue();
        item->Print();
        delete item;
    }

   
    return 0;
}