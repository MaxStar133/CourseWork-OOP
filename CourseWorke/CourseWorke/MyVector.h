#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
        // Sort function
        template <typename Comparator>
        void Sort(Comparator comp) {
            sort(vec.begin(), vec.end(), comp);
        }

        // Find elements in a range based on a predicate
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
                outputFile << "Boat " << (i + 1) << ":\n";
                At(i)->PrintToFile(outputFile);
                outputFile << endl;
            }
            outputFile.close();
        }

        ~MyVector() {
            vec.clear();
        }
    };

