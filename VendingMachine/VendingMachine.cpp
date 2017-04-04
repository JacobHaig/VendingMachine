
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


class item {
public:
	string name;
	double price;
	int qty;

};

class Vending {
public:
	vector<item> slots;
	Vending();
	void dropItem();
	void displayPrice();
	void dispenceCash();
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(Vending, int);
};

Vending::Vending() {

}

void Vending::dropItem() {}
void Vending::displayPrice() {}
void Vending::dispenceCash() {}
void Vending::restock() {}
void Vending::displayError(string e) {}
void Vending::reset() {}
bool Vending::checkInput(int) { return true; }
bool Vending::checkLocation(Vending Lib, int loc) {
	if (loc <= Lib.slots.size()) {
		return true;
	}
	return false;
}

int main() {

	bool notDone = true;

	while (notDone) {
		Vending Lib;

		cout << "Welcome to VenMach Tech INC." << endl;
		cout << "Please make a selection" << endl;
		int input;
		cin >> input;

		// start of selection
		if (Lib.checkLocation(Lib, input)) {

		}
		else {
			cout << "Invalid Location" << endl;
			cout << "Please try again" << endl;
		}
	}
}
