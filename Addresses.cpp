#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

class Addresses {
private:
	std::string street;
	std::string city;
	int number_house;
	int number_room;
	
public:
	Addresses() {
		number_room = number_house = 0;
		street = city = "";
	}
	Addresses(std::string street, std::string city, int number_house, int number_room) {
		this->street = street;
		this->city = city;
		this->number_house = number_house;
		this->number_room = number_room;
	}

	std::string String_output() {
		return street + ", " + city + ", " + std::to_string(number_house) + ", " + std::to_string(number_room) + "\n";
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::ifstream filein("in.txt");
	std::ofstream fileout("out.txt");

	if (filein.is_open()) 
		std::cout << "Все ОК! Файл открыт!\n\n";
	else
	{
		std::cout << "Файл не открыт!\n\n";
		return -1;
	}
	std::string street;
	std::string city;
	int number_house;
	int number_room;

	int amount;

	filein >> amount;
	Addresses* address_amount = new Addresses[amount];

    fileout << amount << "\n";

	for (int i = 0; i < amount; ++i) {
		filein >> street;
		filein >> city;
		filein >> number_house;
		filein >> number_room;
		Addresses address(street, city, number_house, number_room);
		
		address_amount[i] = address;

	}
	
	for (int i = amount - 1; i >= 0; --i) {
		fileout << address_amount[i].String_output();
	}
	delete[] address_amount;
}