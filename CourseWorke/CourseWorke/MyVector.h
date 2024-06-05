#pragma once
#include <iostream>
#include <vector>
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

template <typename T>
    class MyVector {
    private:
        std::vector<T> vec;

    public:
        // Конструкторы
        MyVector() {};

        T& At(size_t index) {
            return vec.at(index);
        }

        void Push_back(const T& value) {
            vec.push_back(value);
        }

        void Pop_back() {
            vec.pop_back();
        }

        T& Front() {
            return vec.front();
        }

        T& Back() {
            return vec.back();
        }

        size_t Size() const {
            return vec.size();
        }

        bool Empty() const {
            return vec.empty();
        }

        typename std::vector<T>::iterator Begin() {
            return vec.begin();
        }

        typename std::vector<T>::iterator End() {
            return vec.end();
        }

        template <typename Comparator>
        void Sort(Comparator comp) {
            sort(vec.begin(), vec.end(), comp);
        }

        template <typename Predicate>
        std::vector<T> FindInRange(Predicate pred) const {
            std::vector<T> result;
            for (const auto& item : vec) {
                if (pred(item)) {
                    result.push_back(item);
                }
            }
            return result;
        }

        void OutputToFile(const string& filename) {
            ofstream outputFile(filename);
            if (!outputFile.is_open()) {
                cout << "Ошибка: Не удалось открыть файл для записи.\n";
                return;
            }
            for (size_t i = 0; i < Size(); ++i) {
                At(i)->PrintToFile(outputFile);
            }
            outputFile.close();
        }

 /*       void InputFromFile(const string& filename) {
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
                    Push_back(boat);
                }
                else if (type == "ENGINE_POWERED_WATER_TRANSPORT") {
                    EnginePoweredWaterTransport* boat = new EnginePoweredWaterTransport();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "CATAMARAN") {
                    Catamaran* boat = new Catamaran();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "SAIL_BOAT") {
                    Sailboat* boat = new Sailboat();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "SUBMARINE") {
                    Submarine* boat = new Submarine();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "TOURIST_BOAT") {
                    TouristBoat* boat = new TouristBoat();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "CRUISE_LINER") {
                    CruiseLiner* boat = new CruiseLiner();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
                else if (type == "NUCLEAR_SUBMARINE") {
                    NuclearSubmarine* boat = new NuclearSubmarine();
                    boat->ReadFromFile(inputFile);
                    Push_back(boat);
                }
            }
            inputFile.close();
        }*/

        ~MyVector() {
            vec.clear();
        }
    };

