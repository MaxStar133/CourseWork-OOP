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
        std::cout << "Список действий." << endl;
        std::cout << "----------------" << endl;
        std::cout << "1.Загрузить файл." << endl;
        std::cout << "2.Список транспорта." << endl;
        std::cout << "3.Создать транспорт." << endl;
        std::cout << "4.Осортировать транспорта." << endl;
        std::cout << "5.Найти транспорт." << endl;
        std::cout << "6.Сохранить в файл" << endl;
        std::cout << "7.Закончить работу." << endl << endl;
    }

    void ShowEntity() {
        std::cout << "-------------------------" << endl;
        std::cout << "Виды водного транспорта." << endl;
        std::cout << "-------------------------" << endl;
        std::cout << "1. Парусник." << endl;
        std::cout << "2. Катамаран." << endl;
        std::cout << "3. Круизный лайнер." << endl;
        std::cout << "4. Атомная подлодка." << endl << endl;
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
			std::cout << "Выберите действие: ";

			std::cin >> action;

			if (action == 7) {
				std::cout << "---------------------------Завершение работы---------------------------" << endl;
				break;
			}
			switch (action)
			{
			case 1: 
				std::cout << "Введите путь до файла и его имя: ";
				std::cin >> nameFile;
                inputFile.open(nameFile);
                if (!inputFile.is_open()) {
                    std::cout << "Ошибка: Не удалось открыть файл для чтения.\n";
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
                            std::cout << "Ошибка: Не удалось открыть файл для чтения.\n";
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
				break;

			case 2:
                std::cout << "---------------------------Содержимое очереди---------------------------" << endl;
                for (size_t i = 0; i < queue.Size(); ++i) {
                    queue.At(i)->Print();
					cout << endl;
                }
				std::cout << "---------------------------Парусники---------------------------" << endl;
				std::cout << sailboatVec << endl;
				std::cout << "---------------------------Катамараны---------------------------" << endl;
				std::cout << catamaranVec << endl;
				std::cout << "---------------------------Атомные подлодки---------------------------" << endl;
				std::cout << nuclearSubmarineVec << endl;
				std::cout << "---------------------------Круизные лайнеры---------------------------" << endl;
				std::cout << cruiseLinerVec << endl;
				break;

			case 3: 
				ShowEntity();
				std::cout << "Выберите вид транспорта: ";
				std::cin >> action;
				double maxSpeed;
				int passengerCapacity;
				std::cout << "Введите имя транспорта: ";
				std::cin >> name;
				std::cout << "Введите максимальную скорость транспорта: ";
				std::cin >> maxSpeed;
				std::cout << "Введите вместимость пассажиров: ";
				std::cin >> passengerCapacity;
				if (action == 1) {
					int sailArea;
					std::cout << "Введите площадь паруса: ";
                    std::cin >> sailArea;
					try {
						Sailboat* boat = new Sailboat(name, maxSpeed, passengerCapacity, sailArea);
						sailboatVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (exception ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
				}
				if (action == 2) {
					int numberOfPedals;
					std::cout << "Введите количество педалий: ";
					std::cin >> numberOfPedals;
					try {
						Catamaran* boat = new Catamaran(name, maxSpeed, passengerCapacity, numberOfPedals);
						catamaranVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (exception ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
				}
				else if (action == 3) {
					int powerEngine;
					int ticketPrice;
					int heightWaterSlides;
					std::cout << "Введите мощность двигателя: ";
					std::cin >> powerEngine;
					std::cout << "Введите стоимость билета: ";
					std::cin >> ticketPrice;
					std::cout << "Введите высоту водных горок: ";
					std::cin >> heightWaterSlides;
					try {
						CruiseLiner* boat = new CruiseLiner(name, maxSpeed, passengerCapacity, powerEngine, ticketPrice, heightWaterSlides);
						cruiseLinerVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (exception ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
				}
				else if (action == 4) {
					int powerEngine;
					double divingDepth;
					double powerAtomicBomb;
					std::cout << "Введите мощность двигателя: ";
					std::cin >> powerEngine;
					std::cout << "Введите глубину погружения: ";
					std::cin >> divingDepth;
					std::cout << "Введите мощность ядерного заряда: ";
					std::cin >> powerAtomicBomb;
					try {
						NuclearSubmarine* boat = new NuclearSubmarine(name, maxSpeed, passengerCapacity, powerEngine, divingDepth, powerAtomicBomb);
						nuclearSubmarineVec.Push_back(boat);
						queue.Enqueue(boat);
					}
					catch (exception ex) {
						std::cout << "---------------------------" << ex.what() << "---------------------------" << endl;
					}
				}
				else {
					std::cout << "---------------------------Неизвестный вид транспорта---------------------------" << endl;
				}
				break;

			case 4: 

				std::cout << "По какому признаку вы бы хотели отсортировать транспорт?" << endl;
				std::cout << "1.Скорость" << endl;
				std::cout << "2.Вместимость пассажир" << endl;
				std::cout << "Введите номер признака для сортировки: ";
				std::cin >> action;
				int sort;
				if (action == 1) {
					std::cout << "1. Сортировать по возрастанию" << endl;
					std::cout << "2. Сортировать по убыванию" << endl;
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
					else std::cout << "Неверный выбор." << endl;
						}
				else if (action == 2) {
					std::cout << "1. Сортировать по возрастанию" << endl;
					std::cout << "2. Сортировать по убыванию" << endl;
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
					else std::cout << "Неверный выбор." << endl;
				}
				else {
					std::cout << "---------------------------Неизвестный признак---------------------------" << endl;
					break;
				}
				std::cout << "---------------------------Сортировка завершена---------------------------" << endl;
				break;

			case 5: 
				std::cout << "По какому признаку вы бы хотели найти объект?" << endl;
				std::cout << "1.Имя" << endl;
				std::cout << "2.В диапозоне скорости" << endl;
				std::cout << "3.В диапозоне вместимости пассажир: "<< endl;
				std::cin >> action;
				int min;
				int max;

				if (action == 1) {
					std::cout << "Введите имя объекта которое хотите найти:" << endl;
					std::cin >> name;
					queue.PrintByName(name);
				}
				else if (action == 2) {
					std::cout << "Ввведите диапозон от min до max." << endl;
					std::cout << "Ввведите min." << endl;
					std::cin >> min;
					std::cout << "Ввведите max." << endl;
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
							std::cout << "Ввведите диапозон от min до max." << endl;
							std::cout << "Ввведите min." << endl;
							std::cin >> min;
							std::cout << "Ввведите max." << endl;
							std::cin >> max;

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
					std::cout << "---------------------------Неизвестный признак---------------------------" << endl;
					break;
				}
				break;
			case 6: 
				std::cout << "Введите путь до файла и его имя: ";
				cin >> nameFile;
				queue.OutputToFile(nameFile);
				cout << "---------------------------Файл успешно сохранён---------------------------" << endl;
				break;
#pragma endregion
			default:
				std::cout << "---------------------------Неизвестная команда, введите еще раз---------------------------" << endl;
				break;
			}
		}

        //MyVector<WaterTransport*> fleet;
       

        //WaterTransport* boat1 = new WaterTransport();
        //boat1->SetName("Boat 1");
        //boat1->SetMaxSpeed(1);
        //boat1->SetPassengerCapacity(10);

        //EnginePoweredWaterTransport* boat2 = new EnginePoweredWaterTransport();
        //boat2->SetName("Boat 2");
        //boat2->SetMaxSpeed(10);
        //boat2->SetPassengerCapacity(20);
        //boat2->SetPowerEngine(500);

        //EnginePoweredWaterTransport* boat3 = new EnginePoweredWaterTransport();
        //boat3->SetName("Boat 3");
        //boat3->SetMaxSpeed(40);
        //boat3->SetPassengerCapacity(20);
        //boat3->SetPowerEngine(500);

        //EnginePoweredWaterTransport* boat4 = new EnginePoweredWaterTransport();
        //boat4->SetName("Boat 4");
        //boat4->SetMaxSpeed(40);
        //boat4->SetPassengerCapacity(20);
        //boat4->SetPowerEngine(500);

        //fleet.Push_back(boat1);
        //fleet.Push_back(boat2);
        //fleet.Push_back(boat3);
        //fleet.Push_back(boat4);
        //std::cout << fleet << endl;
        //boat1->SetMaxSpeed(2);

        //fleet.OutputToFile("C:/Users/ov4in/OneDrive/Рабочий стол/DataSstd::cince/Test.txt");

        //MyVector<WaterTransport*> newFleet;
        //newFleet.InputFromFile("C:/Users/ov4in/OneDrive/Рабочий стол/DataSstd::cince/Test.txt");

        //std::cout << "==============================" << endl;
        //std::cout << newFleet << endl;
   
        //std::cout << "==============================" << endl;

        //queue.Enqueue(boat1);
        //queue.Enqueue(boat2);


        //for (size_t i = 0; i < fleet.Size(); ++i) {
        //    fleet.At(i)->Print();
        //}

        //fleet.Sort([](WaterTransport* a, WaterTransport* b) {
        //    return a->GetMaxSpeed() < b->GetMaxSpeed();
        //    });

        //std::cout << "\nSorted fleet by max speed:\n";
        //for (size_t i = 0; i < fleet.Size(); ++i) {
        //    fleet.At(i)->Print();
        //}

        //// Find all boats with max speed between 0 and 10
        //auto result = fleet.FindInRange([](WaterTransport* boat) {
        //    return boat->GetMaxSpeed() >= 0 && boat->GetMaxSpeed() <= 10;
        //    });

        //std::cout << "\nBoats with max speed between 0 and 10:\n";
        //for (const auto& boat : result) {
        //    boat->Print();
        //}
        //std::cout << endl;
        //std::cout << endl;

        //std::cout << fleet << endl;

        //std::cout << "\nQueue\n";
        //for (size_t i = 0; i < queue.Size(); ++i) {
        //    queue.At(i)->Print();
        //}
        //queue.OutputToFile("queue_data.txt");
        //TmpQueue<IWaterTransport> newQueue;
        //newQueue.InputFromFile("queue_data.txt");

        //std::cout << "==============================" << endl;
        //for (size_t i = 0; i < newQueue.Size(); ++i) {
        //    newQueue.At(i)->Print();
        //}
        //std::cout << "==============================" << endl;


        //std::cout << "Original queue:\n";
        //for (size_t i = 0; i < queue.Size(); ++i) {
        //    queue.At(i)->Print();
        //}std::cout << "==============================" << endl;
        //queue.PrintByName("Boat 1");
        //std::cout << "==============================" << endl;


        return 0;
    }