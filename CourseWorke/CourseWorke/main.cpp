#include <iostream>
#include "TmpQueue.h"
#include "MyVector.h"
#include "IWaterTransport.h"
#include "WaterTransport.h"
#include "EnginePoweredWaterTransport.h"
#include "TouristBoat.h"
#include "Sailboat.h"
#include "Catamaran.h"
#include "CruiseLiner.h"
#include "NuclearSubmarine.h"
#include "Windows.h"   
#include <fstream>
#include <string>

    using namespace std;

    template <typename T>
    ostream& operator<<(ostream& os, MyVector<T*>& vec) {
        for (size_t i = 0; i < vec.Size(); ++i) {
            vec.At(i)->Print();
            os << endl;
        }
        return os;
    }

    void ShowCommands() {
        std::cout << "----------------" << endl;
        std::cout << "������ ��������." << endl;
        std::cout << "----------------" << endl;
        std::cout << "1.��������� ����." << endl;
        std::cout << "2.������ ����������." << endl;
        std::cout << "3.������� ���������." << endl;
        std::cout << "4.������������ ����������." << endl;
        std::cout << "5.����� ���������." << endl;
        std::cout << "6.��������� � ����" << endl;
        std::cout << "7.��������� ������." << endl << endl;
    }

    void ShowEntity() {
        std::cout << "-------------------------" << endl;
        std::cout << "���� ������� ����������." << endl;
        std::cout << "-------------------------" << endl;
        std::cout << "1. ��������." << endl;
        std::cout << "2. ���������." << endl;
        std::cout << "3. �������� ������." << endl;
        std::cout << "4. ������� ��������." << endl << endl;
    }

    int main() {
        std::setlocale(LC_ALL, "Russian");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
 
        string nameFile;
        int action = 0;
        ifstream inputFile;
        string type;
        string name;
        TmpQueue<IWaterTransport> queue;
        MyVector<Sailboat*> sailboatVec;
        MyVector<Catamaran*> catamaranVec;
        MyVector<NuclearSubmarine*> nuclearSubmarineVec;
        MyVector<CruiseLiner*> cruiseLinerVec;

		while (true) {
			ShowCommands();
			std::cout << "�������� ��������: ";

			std::cin >> action;

			if (action == 7) {
				std::cout << "---------------------------���������� ������---------------------------" << endl;
				break;
			}
			switch (action)
			{
			case 1: 
				std::cout << "������� ���� �� ����� � ��� ���: ";
				std::cin >> nameFile;
                inputFile.open(nameFile);
                if (!inputFile.is_open()) {
                    std::cout << "������: �� ������� ������� ���� ��� ������.\n";
                    break;
                }
						try {
								queue.InputFromFile(nameFile);
						}
						catch (invalid_argument ex) {
							std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
						}
                        inputFile.close();

                        inputFile.open(nameFile);
                        if (!inputFile.is_open()) {
                            std::cout << "������: �� ������� ������� ���� ��� ������.\n";
                            break;
                        }
                        while (getline(inputFile, type)) {
                            if (type == "CATAMARAN") {
								Catamaran* boat = new Catamaran();

                                try {
                                    boat->ReadFromFile(inputFile);
                                    catamaranVec.Push_back(boat);
                                }
                                catch (invalid_argument ex) {
                                    std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
                                }
                            }
                            else if (type == "SAIL_BOAT") {
								Sailboat* boat = new Sailboat();

                                try {
                                    boat->ReadFromFile(inputFile);
                                    sailboatVec.Push_back(boat);
                                }
                                catch (invalid_argument ex) {
                                    std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
                                }
                            }
                            else if (type == "CRUISE_LINER") {
								CruiseLiner* boat = new CruiseLiner();

                                try {
                                    boat->ReadFromFile(inputFile);
                                    cruiseLinerVec.Push_back(boat);
                                }
                                catch (invalid_argument ex) {
                                    std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
                                }
                            }
                            else if (type == "NUCLEAR_SUBMARINE") {
								NuclearSubmarine* boat = new NuclearSubmarine();

                                try {
                                    boat->ReadFromFile(inputFile);
                                    nuclearSubmarineVec.Push_back(boat);
                                }
                                catch (invalid_argument ex) {
                                    std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
                                }
                            }
                        }
                        inputFile.close();
						cout << "---------------------------���� ������� ��������---------------------------" << endl;
				break;

			case 2:
                std::cout << "---------------------------���������� �������---------------------------" << endl;
                for (size_t i = 0; i < queue.Size(); ++i) {
                    queue.At(i)->Print();
					cout << endl;
                }
				std::cout << "---------------------------���������---------------------------" << endl;
				std::cout << sailboatVec << endl;
				std::cout << "---------------------------����������---------------------------" << endl;
				std::cout << catamaranVec << endl;
				std::cout << "---------------------------������� ��������---------------------------" << endl;
				std::cout << nuclearSubmarineVec << endl;
				std::cout << "---------------------------�������� �������---------------------------" << endl;
				std::cout << cruiseLinerVec << endl;
				break;

			case 3: 
				ShowEntity();
				std::cout << "�������� ��� ����������: ";
				std::cin >> action;
				double maxSpeed;
				int passengerCapacity;
				std::cout << "������� ��� ����������: ";
				std::cin >> name;
				std::cout << "������� ������������ �������� ���������� (��/�): ";
				std::cin >> maxSpeed;
				std::cout << "������� ����������� ����������: ";
				std::cin >> passengerCapacity;
				if (action == 1) {
					int sailArea;
					std::cout << "������� ������� ������ (��. �): ";
                    std::cin >> sailArea;
					try {
						Sailboat* boat = new Sailboat(name, maxSpeed, passengerCapacity, sailArea);
						sailboatVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (invalid_argument ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
					break;
				}
				if (action == 2) {
					int numberOfPedals;
					std::cout << "������� ���������� �������: ";
					std::cin >> numberOfPedals;
					try {
						Catamaran* boat = new Catamaran(name, maxSpeed, passengerCapacity, numberOfPedals);
						catamaranVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (invalid_argument ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
					break;
				}
				else if (action == 3) {
					int powerEngine;
					int ticketPrice;
					int heightWaterSlides;
					std::cout << "������� �������� ��������� (�/�): ";
					std::cin >> powerEngine;
					std::cout << "������� ��������� ������ (���.): ";
					std::cin >> ticketPrice;
					std::cout << "������� ������ ������ ����� (�): ";
					std::cin >> heightWaterSlides;
					try {
						CruiseLiner* boat = new CruiseLiner(name, maxSpeed, passengerCapacity, powerEngine, ticketPrice, heightWaterSlides);
						cruiseLinerVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (invalid_argument ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
					break;
				}
				else if (action == 4) {
					int powerEngine;
					double divingDepth;
					double powerAtomicBomb;
					std::cout << "������� �������� ��������� (�/�): ";
					std::cin >> powerEngine;
					std::cout << "������� ������� ���������� (�): ";
					std::cin >> divingDepth;
					std::cout << "������� �������� �������� ������ (��): ";
					std::cin >> powerAtomicBomb;
					try {
						NuclearSubmarine* boat = new NuclearSubmarine(name, maxSpeed, passengerCapacity, powerEngine, divingDepth, powerAtomicBomb);
						nuclearSubmarineVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (invalid_argument ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
					break;
				}
				else {
					std::cout << "---------------------------����������� ��� ����������---------------------------" << endl;
				}
				break;

			case 4: 

				std::cout << "�� ������ �������� �� �� ������ ������������� ���������?" << endl;
				std::cout << "1.��������" << endl;
				std::cout << "2.����������� ����������" << endl;
				std::cout << "������� ����� �������� ��� ����������: ";
				std::cin >> action;
				int sort;
				if (action == 1) {
					std::cout << "1. ����������� �� �����������" << endl;
					std::cout << "2. ����������� �� ��������" << endl;
					std::cin >> sort;
					if (sort == 1) {
						sailboatVec.Sort([](Sailboat* a, Sailboat* b) {
							return a->GetMaxSpeed() < b->GetMaxSpeed();
							});
						catamaranVec.Sort([](Catamaran* a, Catamaran* b) {
							return a->GetMaxSpeed() < b->GetMaxSpeed();
							});
						nuclearSubmarineVec.Sort([](NuclearSubmarine* a, NuclearSubmarine* b) {
							return a->GetMaxSpeed() < b->GetMaxSpeed();
							});
						cruiseLinerVec.Sort([](CruiseLiner* a, CruiseLiner* b) {
							return a->GetMaxSpeed() < b->GetMaxSpeed();
							});
					}
					else if (sort == 2) {
						sailboatVec.Sort([](Sailboat* a, Sailboat* b) {
							return a->GetMaxSpeed() > b->GetMaxSpeed();
							});
						catamaranVec.Sort([](Catamaran* a, Catamaran* b) {
							return a->GetMaxSpeed() > b->GetMaxSpeed();
							});
						nuclearSubmarineVec.Sort([](NuclearSubmarine* a, NuclearSubmarine* b) {
							return a->GetMaxSpeed() > b->GetMaxSpeed();
							});
						cruiseLinerVec.Sort([](CruiseLiner* a, CruiseLiner* b) {
							return a->GetMaxSpeed() > b->GetMaxSpeed();
							});
					}
					else std::cout << "�������� �����." << endl;
						}
				else if (action == 2) {
					std::cout << "1. ����������� �� �����������" << endl;
					std::cout << "2. ����������� �� ��������" << endl;
					std::cin >> sort;
					if (sort == 1) {
						sailboatVec.Sort([](Sailboat* a, Sailboat* b) {
							return a->GetPassengerCapacity() < b->GetPassengerCapacity();
							});
						catamaranVec.Sort([](Catamaran* a, Catamaran* b) {
							return a->GetPassengerCapacity() < b->GetPassengerCapacity();
							});
						nuclearSubmarineVec.Sort([](NuclearSubmarine* a, NuclearSubmarine* b) {
							return a->GetPassengerCapacity() < b->GetPassengerCapacity();
							});
						cruiseLinerVec.Sort([](CruiseLiner* a, CruiseLiner* b) {
							return a->GetPassengerCapacity() < b->GetPassengerCapacity();
							});
					}
					else if (sort == 2) {
						sailboatVec.Sort([](Sailboat* a, Sailboat* b) {
							return a->GetPassengerCapacity() > b->GetPassengerCapacity();
							});
						catamaranVec.Sort([](Catamaran* a, Catamaran* b) {
							return a->GetPassengerCapacity() > b->GetPassengerCapacity();
							});
						nuclearSubmarineVec.Sort([](NuclearSubmarine* a, NuclearSubmarine* b) {
							return a->GetPassengerCapacity() > b->GetPassengerCapacity();
							});
						cruiseLinerVec.Sort([](CruiseLiner* a, CruiseLiner* b) {
							return a->GetPassengerCapacity() > b->GetPassengerCapacity();
							});
					}
					else std::cout << "�������� �����." << endl;
				}
				else {
					std::cout << "---------------------------����������� �������---------------------------" << endl;
					break;
				}
				std::cout << "---------------------------���������� ���������---------------------------" << endl;
				break;

			case 5: 
				std::cout << "�� ������ �������� �� �� ������ ����� ������?" << endl;
				std::cout << "1.���" << endl;
				std::cout << "2.� ��������� ��������" << endl;
				std::cout << "3.� ��������� ����������� ��������: "<< endl;
				std::cin >> action;
				int min;
				int max;

				if (action == 1) {
					std::cout << "������� ��� ������� ������� ������ �����:" << endl;
					std::cin >> name;
					queue.PrintByName(name);
				}
				else if (action == 2) {
					std::cout << "�������� �������� �� min �� max." << endl;
					std::cout << "�������� min." << endl;
					std::cin >> min;
					std::cout << "�������� max." << endl;
					std::cin >> max;

					auto result1 = sailboatVec.FindInRange([min, max](Sailboat* boat) {
						return boat->GetMaxSpeed() >= min && boat->GetMaxSpeed() <= max;
						});
					for (const auto& boat : result1) {
						boat->Print();
						cout << endl;
					}
					auto result2 = catamaranVec.FindInRange([min, max](Catamaran* boat) {
						return boat->GetMaxSpeed() >= min && boat->GetMaxSpeed() <= max;
						});
					for (const auto& boat : result2) {
						boat->Print();
						cout << endl;
					}
					auto result3 = nuclearSubmarineVec.FindInRange([min, max](NuclearSubmarine* boat) {
						return boat->GetMaxSpeed() >= min && boat->GetMaxSpeed() <= max;
						});
					for (const auto& boat : result3) {
						boat->Print();
						cout << endl;
					}
					auto result4 = cruiseLinerVec.FindInRange([min, max](CruiseLiner* boat) {
						return boat->GetMaxSpeed() >= min && boat->GetMaxSpeed() <= max;
						});
					for (const auto& boat : result4) {
						boat->Print();
						cout << endl;
					}
				}
				else if (action == 3) {
							std::cout << "�������� �������� �� min �� max." << endl;
							std::cout << "�������� min." << endl;
							std::cin >> min;
							std::cout << "�������� max." << endl;
							std::cin >> max;
							std::cout << endl;
							auto result1 = sailboatVec.FindInRange([min, max](Sailboat* boat) {
								return boat->GetPassengerCapacity() >= min && boat->GetPassengerCapacity() <= max;
								});
							for (const auto& boat : result1) {
								boat->Print();
								cout << endl;
							}
							auto result2 = catamaranVec.FindInRange([min, max](Catamaran* boat) {
								return boat->GetPassengerCapacity() >= min && boat->GetPassengerCapacity() <= max;
								});
							for (const auto& boat : result2) {
								boat->Print();
								cout << endl;
							}
							auto result3 = nuclearSubmarineVec.FindInRange([min, max](NuclearSubmarine* boat) {
								return boat->GetPassengerCapacity() >= min && boat->GetPassengerCapacity() <= max;
								});
							for (const auto& boat : result3) {
								boat->Print();
								cout << endl;
							}
							auto result4 = cruiseLinerVec.FindInRange([min, max](CruiseLiner* boat) {
								return boat->GetPassengerCapacity() >= min && boat->GetPassengerCapacity() <= max;
								});
							for (const auto& boat : result4) {
								boat->Print();
								cout << endl;
							}
								}
				else {
					std::cout << "---------------------------����������� �������---------------------------" << endl;
					break;
				}
				break;
			case 6: 
				std::cout << "������� ���� �� ����� � ��� ���: ";
				cin >> nameFile;
				queue.OutputToFile(nameFile);
				cout << "---------------------------���� ������� �������---------------------------" << endl;
				break;

			default:
				std::cout << "---------------------------����������� �������, ������� ��� ���---------------------------" << endl;
				break;
			}
		}


        return 0;
    }