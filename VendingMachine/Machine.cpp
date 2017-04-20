#include "stdafx.h"
#include "Machine.h"

#include <iostream>
#include <windows.h>

using namespace std;

Machine::Machine() {}
Machine::~Machine() {}

void Machine::totalMoney() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(3),SHORT(29) });
	cout << "Total money in machine " << totalMoneys;
}
void Machine::dropItem(Machine *cafe, vector<int> inputs) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(30),SHORT(9) });
	cout << "Droping Items" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(30),SHORT(10) });
	cout << "========================";

	for (int i = 0; i < inputs.size(); i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(30),SHORT(11 + i) });
		cout << i+1 << ".  " << cafe->slots[inputs[i]].name;
	}
	cout << endl;
}
void Machine::displayItemInformation(Machine *cafe, vector<int> inputs) {
	if (inputs.size() <= 5)
		for (int i = 0; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(63),SHORT(i + 12) });
			cout << i + 1 << ". " << cafe->slots[inputs[i]].name << "- " << cafe->slots[inputs[i]].price << endl;
		}
	if (inputs.size() > 5)
		for (int i = 5; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(88),SHORT(i + 12 - 5) });
			cout << i + 1 << ". " << cafe->slots[inputs[i]].name << "- " << cafe->slots[inputs[i]].price << endl;
		}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(100),SHORT(19) });
	cout << "       ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(100),SHORT(19) });
	float sum = 0;
	for each(int v in inputs)
		sum += cafe->slots[v].price;
	cout << "Total: $" << sum;
}

void Machine::dispenceCash(double moneys)
{
	int quarter = 0, dime = 0, nickel = 0, penny = 0;
	int money = static_cast<int>(ceil(moneys * 100));

	while (money >= 25)
	{
		quarter++;
		money -= 25;
	}
	while (money >= 10)
	{
		dime++;
		money -= 10;
	}
	while (money >= 5)
	{
		nickel++;
		money -= 5;
	}
	while (money >= 1)
	{
		penny++;
		money -= 1;
	}

	int x = 65, y = 11;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x),SHORT(y - 1) });
	cout << "Your Change" << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x),SHORT(y + 0) });
	cout << "quarters:" << quarter << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x),SHORT(y + 1) });
	cout << "dimes:" << dime << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x),SHORT(y + 2) });
	cout << "nickels:" << nickel << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x),SHORT(y + 3) });
	cout << "pennies:" << penny << endl;
}
void Machine::restock() {}
void Machine::displayError(string e) {
	cout << e << " Error";
}
void Machine::reset() {}
bool Machine::checkInput(int) { return true; }
bool Machine::checkLocation(Machine cafe, int loc) {
	if (loc <= cafe.slots.size()) return true; else return false;
}