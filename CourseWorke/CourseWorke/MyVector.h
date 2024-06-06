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

        ~MyVector() {
            vec.clear();
        }
    };

