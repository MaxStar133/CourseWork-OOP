#include "MyVector.h"
#include <iostream>
#include <fstream>

using namespace std;

MyVector::MyVector() {
	begin = NULL; end = NULL;
	count = 0;
}

MyVector::MyVector(const MyVector& v) {
	begin = end = NULL;
	count = 0;
	Node* tmp = v.begin;
	while (tmp != NULL) {
		add(tmp->data);
		tmp = tmp->next;
	}
}

MyVector::MyVector(string pathToFile) : MyVector::MyVector() {
	setPathToFile(pathToFile);
}

MyVector::~MyVector() {
	if (!isEmpty()) {
		Node* tmp = NULL;
		while (tmp != NULL) {
			tmp = end;
			end = end->prev;
			delete(tmp);
		}
	}
}

bool MyVector::isEmpty() const {
	return begin == NULL;
}

int MyVector::size() {
	return count;
}

void MyVector::add(WaterTransport* d) {
	if (isEmpty()) {
		begin = new Node;
		begin->data = d;
		end = begin;
	}
	else {
		end->next = new Node;
		end->next->prev = end;
		end = end->next;
		end->data = d;
		end->next = NULL;
	}
	count++;
}

void MyVector::removeLast() {
	if (!isEmpty()) {
		Node* tmp = end;
		end = end->prev;
		delete(tmp);
		count--;
		if (count == 0) {
			begin = NULL;
		}
	}
	else {
		throw exception("Vector is empty");
	}
}

//void MyVector::print() const {
//	if (isEmpty()) {
//		cout << "Вектор пуст." << endl;
//		return;
//	}
//
//	Node* tmp = begin;
//	int currentPos = 0;
//	while (currentPos < count) {
//		cout << "\tЭлемент " << currentPos << ":" << endl;
//		tmp->data->printData();
//		tmp = tmp->next;
//		currentPos++;
//	}
//}

void MyVector::clear() {
	while (!isEmpty()) removeLast();
}

WaterTransport*& MyVector::getData(int pos) const {
	if (isEmpty())
		throw exception("Vector is empty");
	if (pos > count)
		throw exception("Position is bigger than count of elemens");
	if (pos < 0)
		throw exception("Invalid position");

	Node* tmp = begin;
	int currentPos = 0;
	while (tmp != NULL && currentPos < pos) {
		tmp = tmp->next;
		currentPos++;
	}
	return tmp->data;
}

//void MyVector::sortByVoltage() {
//	if (isEmpty())
//		return;
//
//	for (int i = 0; i < count; i++) {
//		for (int j = count - 1; j > i; j--) {
//			WaterTransport*& tmp1 = getData(j);
//			WaterTransport*& tmp2 = getData(j - 1);
//
//			if (tmp1->getVoltage() < tmp2->getVoltage()) {
//				swap(tmp1, tmp2);
//			}
//		}
//	}
//}
//
//void MyVector::vfind(string name) const {
//	if (isEmpty())
//		throw exception("Vector is empty");
//	Node* tmp = begin;
//	while (tmp != NULL) {
//		if (name == tmp->data->getName()) tmp->data->printData();
//		tmp = tmp->next;
//
//	}
//}
//
//void MyVector::setPathToFile(string path) {
//	pathToFile = path;
//}
//
//void MyVector::readFromFile() {
//	ifstream file(pathToFile);
//	if (!file.is_open()) throw exception("Error opening file");
//
//	while (!file.eof()) {
//		string className;
//		string name;
//		double wattage;
//		double voltage;
//		double amperage;
//
//		file >> className;
//		if (className == "ElectricalMachine") {
//			file >> name >> wattage >> voltage >> amperage;
//
//			add(new WaterTransport(name, wattage, voltage, amperage));
//		}
//		else if (className == "Generator") {
//			double fuelTankCapacity;
//			file >> name >> wattage >> voltage >> amperage >> fuelTankCapacity;
//
//			add(new Generator(name, wattage, voltage, amperage, fuelTankCapacity));
//		}
//		else if (className == "DieselGenerator") {
//			double fuelTankCapacity;
//			double fuelConsumption;
//			file >> name >> wattage >> voltage >> amperage >> fuelTankCapacity >> fuelConsumption;
//
//			add(new DieselGenerator(name, wattage, voltage, amperage, fuelTankCapacity, fuelConsumption));
//		}
//		else if (className == "GasGenerator") {
//			double fuelTankCapacity;
//			bool possibilityOfAutorun;
//			string possibilityOfAutorunString;
//
//			file >> name >> wattage >> voltage >> amperage >> fuelTankCapacity >> possibilityOfAutorunString;
//
//			possibilityOfAutorun = possibilityOfAutorunString._Equal("yes")
//				? true
//				: false;
//
//			add(new GasGenerator(name, wattage, voltage, amperage, fuelTankCapacity, possibilityOfAutorun));
//		}
//		else if (className == "MobileGenerator") {
//			double fuelTankCapacity;
//			bool possibilityOfAutorun;
//			double fuelConsumption;
//			string possibilityOfAutorunString;
//			double soundproofingMaterialThickness;
//
//			file >> name >> wattage >> voltage >> amperage >> fuelTankCapacity >> fuelConsumption >> soundproofingMaterialThickness >> possibilityOfAutorunString;
//
//			possibilityOfAutorun = possibilityOfAutorunString._Equal("yes")
//				? true
//				: false;
//
//			add(new MobileGenerator(name,
//				wattage,
//				voltage,
//				amperage,
//				fuelTankCapacity,
//				fuelConsumption,
//				possibilityOfAutorun,
//				soundproofingMaterialThickness)
//			);
//		}
//		else if (className == "") continue;
//		else throw exception("Error reading from file: invalid class specified");
//	}
//
//	file.close();
//}
//
//void MyVector::saveToFile() {
//	ofstream file(pathToFile, std::ofstream::out | std::ofstream::trunc);
//	Node* tmp = begin;
//
//	while (tmp != NULL) {
//		string className = tmp->data->getClassName();
//		file << className << " ";
//		file << tmp->data->getName() << " ";
//		file << tmp->data->getWattage() << " ";
//		file << tmp->data->getVoltage() << " ";
//		file << tmp->data->getAmperage();
//		if (className == "Generator") {
//			Generator* g = dynamic_cast<Generator*>(tmp->data);
//			file << " " << g->getFuelTankCapacity() << endl;
//		}
//		else if (className == "DieselGenerator")
//		{
//			DieselGenerator* dg = dynamic_cast<DieselGenerator*>(tmp->data);
//			file << " " << dg->getFuelTankCapacity() << " ";
//			file << dg->getFuelConsumption() << endl;
//		}
//		else if (className == "GasGenerator") {
//			GasGenerator* gg = dynamic_cast<GasGenerator*>(tmp->data);
//			file << " " << gg->getFuelTankCapacity() << " ";
//			if (gg->getPossibilityOfAutorun()) file << "yes" << endl;
//			else file << "no" << endl;
//		}
//		else if (className == "MobileGenerator") {
//			MobileGenerator* mg = dynamic_cast<MobileGenerator*>(tmp->data);
//			file << " " << mg->getFuelTankCapacity() << " ";
//			file << mg->getFuelConsumption() << " ";
//			file << mg->getSoundproofingMaterialThickness() << " ";
//			if (mg->getPossibilityOfAutorun()) file << "yes" << endl;
//			else file << "no" << endl;
//		}
//		else file << endl;
//
//		tmp = tmp->next;
//	}
//}
