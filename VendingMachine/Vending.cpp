#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <string>

#include <windows.h>
#include <mmsystem.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <thread>

#include "Vending.h"
#include "Screen.h"

vending::vending() {}
void vending::dropItem() {}
void vending::displayItemInformation(vending cafe, vector<int> inputs) {
	for (int j = 0; j < 1; j++) {
		for (int i = j; i < inputs.size() % 6; i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70 + 15 * j),SHORT(i + 12) });
			cout << i + i*j + 1 << ". " << cafe.slots[inputs[i + i*j]].name << "  - " << cafe.slots[inputs[i + i*j]].price << endl;
		}
	}
}

void vending::dispenceCash() {}
void vending::restock() {}
void vending::displayError(string e) {}
void vending::reset() {}
bool vending::checkInput(int) { return true; }
bool vending::checkLocation(vending cafe, int loc) {
	if (loc <= cafe.slots.size()) return true; else return false;

}

item::item(string n, double p, int q) {
	name = n;
	price = p;
	qty = q;
}
