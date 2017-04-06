
#include "stdafx.h"
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

using namespace std;

class item {
public:
	~item();
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
item::~item() {};


class Vending {
public:
	vector<item> slots = {};
	Vending();
	void dropItem();
	void displayItemInformation(Vending, vector<int>);
	void dispenceCash();
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(Vending, int);
};
Vending::Vending() {}
void Vending::dropItem() {}
void Vending::displayItemInformation(Vending cafe, vector<int> inputs) {
	if (inputs.size() <= 5)
		for (int i = 0; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70),SHORT(i + 12) });
			cout << i + 1 << ". " << cafe.slots[inputs[i]].name << "  - " << cafe.slots[inputs[i]].price << endl;
		}
	if (inputs.size() > 5)
		for (int i = 5; i < inputs.size(); i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(88),SHORT(i + 12 - 5) });
			cout << i + 1 << ". " << cafe.slots[inputs[i]].name << "  - " << cafe.slots[inputs[i]].price << endl;
		}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(88),SHORT(18) });
	float sum = 0;
	for each(int v in inputs) {
		sum += cafe.slots[v].price;
	}
	cout << "Total: $" << sum;
}

void Vending::dispenceCash() {}
void Vending::restock() {}
void Vending::displayError(string e) {
	cout << e << " Error";
}
void Vending::reset() {}
bool Vending::checkInput(int) { return true; }
bool Vending::checkLocation(Vending cafe, int loc) {
	if (loc <= cafe.slots.size()) return true; else return false;
}

namespace Screen {
	vector<string> Menu() { // returns Map1 
		vector<string> Map = {
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                          ################################################################                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          #                                                              #                               \n" },
			{ "                          ################################################################                               \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
			{ "                                                                                                                         \n" },
		};
		return Map;
	}
	vector<string> Selection() { // returns Map1 
		vector<string> Map = {
			{ "                                                                                                                         \n" },
			{ "     ########################################                ################    ###############   #################     \n" },
			{ "     #                                      #                #  +        /  #    #    /'__/    #   #     Space     #     \n" },
			{ "     #                                      #                #   +  /+  /   #    #    +__ +    #   #      to       #     \n" },
			{ "     #                                      #                #    +/  +/    #    #    /___/    #   #     select    #     \n" },
			{ "     #                                      #                ################    ###############   #################     \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                             Select your items via the Arrows                \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                #######################################################     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #######################################################     \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     ########################################                                                                            \n" }
		};
		return Map;
	}

	void drawScreen(vector<string> Map) {//This is the "rendering" function
		//vector<string> Map = Screen::Menu();
		for (short i = 0; i < Map.size(); i++)
		{
			for (short j = 0; j < Map[i].length(); j++)
			{
				COORD pos = { j ,i };
				char name = Map[i][j];
				if (name == '#') {
					name = char(219);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 | FOREGROUND_INTENSITY);
				}
				if (name == '+')
					name = char(92);
				if (name != ' ') {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					cout << name;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
		}
	}

	void drawItemsInVend(Vending cafe, int &depth, int arrow = 0) {
		if (arrow > 24 + depth)
			depth++;
		for (int i = depth; i < min(cafe.slots.size(), 24 ) - depth; i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 8 , SHORT(i + 3) });
			if (i == arrow) cout << "*"; else cout << " ";
			cout << "Item: " << cafe.slots[i + depth].name << " Price: $" << cafe.slots[i + depth].price << " Qty: " << cafe.slots[i].qty << "  " << endl;
		}
	}

};

int main() {

	Vending cafe;

	item e("Pie", 1.85, 3);
	cafe.slots.push_back(e);
	e.~item();
	item r("Soda", 1.5, 8);
	cafe.slots.push_back(r);


	int itemsInVendingMachine = 40 - cafe.slots.size();
	for (int i = 0; i < itemsInVendingMachine; i++) {
		item e("Cake", 1.25, 5);
		cafe.slots.push_back(e);
	}

	int depth = 0;
	char input;
	vector<int> inputs;
	int arrow = 3;

	system("CLS");
	Screen::drawScreen(Screen::Selection());

	do {
		Screen::drawItemsInVend(cafe, depth, arrow);
		input = _getch();

		if (input == 'w')if (arrow > 0)arrow--;
		if (input == 's')if (arrow < cafe.slots.size() - 1)arrow++;
		if (input == ' ') if (inputs.size() < 10)inputs.push_back(arrow);

		cafe.displayItemInformation(cafe, inputs);
	} while (input != 'p');

	cout << "Thank you shop again!" << endl;
	getch();
}
