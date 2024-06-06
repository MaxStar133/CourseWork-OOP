#pragma once
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include "IWaterTransport.h"
#include "WaterTransport.h"
#include "EnginePoweredWaterTransport.h"
#include "TouristBoat.h"
#include "Sailboat.h"
#include "Catamaran.h"
#include "CruiseLiner.h"
#include "NuclearSubmarine.h"

using namespace std;

class VoidQueue {
private:
    std::queue<void*> container;

protected:
    void Enqueue(void* item) {
        container.push(item);
    }

    void* Dequeue() {
        if (container.empty()) {
            return nullptr;
        }
        void* item = container.front();
        container.pop();
        return item;
    }

    bool IsEmpty() const {
        return container.empty();
    }

    size_t Size() const {
        return container.size();
    }

    void* At(size_t index) const {
        if (index >= container.size()) {
            return nullptr;
        }
        std::queue<void*> tempQueue = container;
        for (size_t i = 0; i < index; ++i) {
            tempQueue.pop();
        }
        return tempQueue.front();
    }


    void OutputToFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cout << "Ошибка: Не удалось открыть файл для записи.\n";
            return;
        }
        size_t queueSize = Size();
        for (size_t i = 0; i < queueSize; ++i) {
            static_cast<IWaterTransport*>(At(i))->PrintToFile(outputFile); 
        }
        outputFile.close();
    }

    void InputFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cout << "Ошибка: Не удалось открыть файл для чтения.\n";
            return;
        }
        string type;
        while (getline(inputFile, type)) {
            if (type == "WATER_TRANSPORT") {
                WaterTransport* boat = new WaterTransport();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "ENGINE_POWERED_WATER_TRANSPORT") {
                EnginePoweredWaterTransport* boat = new EnginePoweredWaterTransport();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "CATAMARAN") {
                Catamaran* boat = new Catamaran();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "SAIL_BOAT") {
                Sailboat* boat = new Sailboat();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "SUBMARINE") {
                Submarine* boat = new Submarine();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "TOURIST_BOAT") {
                TouristBoat* boat = new TouristBoat();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "CRUISE_LINER") {
                CruiseLiner* boat = new CruiseLiner();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
            else if (type == "NUCLEAR_SUBMARINE") {
                NuclearSubmarine* boat = new NuclearSubmarine();
                boat->ReadFromFile(inputFile);
                Enqueue(boat);
            }
        }
        inputFile.close();
    }

    void PrintByName(const string& name) const {
        std::queue<void*> tempQueue = container;
        bool found = false;
        while (!tempQueue.empty()) {
            void* item = tempQueue.front();
            tempQueue.pop();
        
            if (static_cast<IWaterTransport*>(item)->GetName() == name) {
                static_cast<IWaterTransport*>(item)->Print();
                found = true;
            }
        }
        if (!found) {
            cout << "Объекты с именем '" << name << "' не найдены." << endl;
        }
    }


    ~VoidQueue() {
        while (!container.empty()) {
            container.pop();
        }
    }
};