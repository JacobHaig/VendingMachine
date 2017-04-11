#include "stdafx.h"
#include "Machine.h"

#include <iostream>
#include <windows.h>

using namespace std;

Machine::Machine() {}
Machine::~Machine() {}
void Machine::dropItem() {}
void Machine::displayItemInformation(Machine *cafe, vector<int> inputs) {
	if (inputs.size() <= 5)
		for (int i = 0; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70),SHORT(i + 12) });
			cout << i + 1 << ". " << cafe->slots[inputs[i]].name << "  - " << cafe->slots[inputs[i]].price << endl;
		}
	if (inputs.size() > 5)
		for (int i = 5; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(88),SHORT(i + 12 - 5) });
			cout << i + 1 << ". " << cafe->slots[inputs[i]].name << "  - " << cafe->slots[inputs[i]].price << endl;
		}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(88),SHORT(18) });
	float sum = 0;
	for each(int v in inputs) {
		sum += cafe->slots[v].price;
	}
	cout << "Total: $" << sum;
}

void Machine::dispenceCash() {}
void Machine::restock() {}
void Machine::displayError(string e) {
	cout << e << " Error";
}
void Machine::reset() {}
bool Machine::checkInput(int) { return true; }
bool Machine::checkLocation(Machine cafe, int loc) {
	if (loc <= cafe.slots.size()) return true; else return false;
}


