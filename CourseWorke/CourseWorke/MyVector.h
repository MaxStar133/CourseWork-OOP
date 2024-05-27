#pragma once
#include "WaterTransport.h"
using namespace std;

class MyVector
{
private:
	struct Node { //структура, в которой хранятся все данные об элементе вектора
		WaterTransport* data; // данные 
		Node* next = NULL, * prev = NULL; // указатель на следующий и предыдущий элемент вектора
	};
	Node* begin, * end;
	string pathToFile;
	int count;
public:
	MyVector();
	MyVector(string pathToFile);
	MyVector(const MyVector& v);
	~MyVector();
	bool isEmpty() const; // проверка вектора на пустоту
	int size(); // возвращает размер вектора
	void add(WaterTransport* d);
	void removeLast(); // удаление 
	void print() const; // вывод на экран элемента на указанной позиции
	void clear();
	WaterTransport*& getData(int pos) const; // возвращает элемент на заданной позиции

	void vfind(string name) const;
	void sortByVoltage();

	void setPathToFile(string path);
	void readFromFile();
	void saveToFile();
};

