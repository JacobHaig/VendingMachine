
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;


class item {
public:
	item(string, double, int);
	string name;
	double price;
	int qty;
};

item::item(string n, double p, int q) {
	name = n;
	price = p;
	qty = q;
}


class Vending {
public:
	vector<item> slots = {};
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



Vending::Vending() {}
void Vending::dropItem() {}
void Vending::displayPrice() {}
void Vending::dispenceCash() {}
void Vending::restock() {}
void Vending::displayError(string e) {}
void Vending::reset() {}
bool Vending::checkInput(int) { return true; }
bool Vending::checkLocation(Vending cafe, int loc) {
	if (loc <= cafe.slots.size())
		return true;
	else
		return false;
}

void Display() {}

int main() {
	cout << "Welcome to VenMach Tech INC." << endl;
	cout << "Please make a selection" << endl;

	bool notDone = true;
	int itemsInVendingMachine = 40;
	Vending cafe;



	for (int i = 0; i < itemsInVendingMachine - cafe.slots.size(); i++)
	{
		item e("Cake", 1.25, 5);
		cafe.slots.push_back(e);
	}

	while (notDone) {
		// Input area. Creates a int vector to index later
		string e;
		vector<int> inputs;

		do
		{
			int input;
			cin >> input;

			if (cafe.checkLocation(cafe, input))
				inputs.push_back(input);
			else {
				cout << "Invalid Location" << endl;
				cout << "Please try again" << endl;
			}

			cout << "Would you like to pick more? N/Y" << endl;
			cin >> e;
		} while (e == "Y" || e == "y");


		// start of stuff
		for each (int _item in inputs)
		{
			if (cafe.checkLocation(cafe, _item)) 
				cout << endl << "The " << cafe.slots[_item].name << "'s price is " << cafe.slots[_item].price << "." << endl << endl;
		}
		cout << "Would you like check out?" << endl;
	}

	cout << "Thank you shop again!" << endl;
	getch();
}
