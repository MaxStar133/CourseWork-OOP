#pragma once
#include "WaterTransport.h"
using namespace std;

class MyVector
{
private:
	struct Node { //���������, � ������� �������� ��� ������ �� �������� �������
		WaterTransport* data; // ������ 
		Node* next = NULL, * prev = NULL; // ��������� �� ��������� � ���������� ������� �������
	};
	Node* begin, * end;
	string pathToFile;
	int count;
public:
	MyVector();
	MyVector(string pathToFile);
	MyVector(const MyVector& v);
	~MyVector();
	bool isEmpty() const; // �������� ������� �� �������
	int size(); // ���������� ������ �������
	void add(WaterTransport* d);
	void removeLast(); // �������� 
	void print() const; // ����� �� ����� �������� �� ��������� �������
	void clear();
	WaterTransport*& getData(int pos) const; // ���������� ������� �� �������� �������

	void vfind(string name) const;
	void sortByVoltage();

	void setPathToFile(string path);
	void readFromFile();
	void saveToFile();
};

