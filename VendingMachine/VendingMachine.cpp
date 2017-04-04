#include <iostream>
#include <vector>
#include <string>
#include "stdafx.h"

using namespace std;

struct COORD
{
	int x;
	int y;
};

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

bool Vending::checkLocation(Vending Lib, int loc) {
	if (loc <= Lib.slots.size()) {

	}
};

int main() {

	bool notDone = true;

	while (notDone) {
		Vending Lib();

		cout << “Welcome to VenMach Tech INC.” << endl;
		cout << “Please make a selection” << endl;
		int input;
		cin >> input;

		// start of selection
		if (lib.checkLocation(Lib, input)) {

		}
		else {
			cout << “Invalid Location” << endl;

		}
	}

