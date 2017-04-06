
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
	void displayItemInformation(Vending, int);
	void dispenceCash();
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(Vending, int);
};
Vending::Vending() {}
void Vending::dropItem() {}
void Vending::displayItemInformation(Vending cafe, int _item) {
	cout << "The " << cafe.slots[_item].name << "'s price is " << cafe.slots[_item].price << "." << endl;
}

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
			{ "     #                                      #                #  +        /  #    #    /'__/    #   #               #     \n" },
			{ "     #                                      #                #   +  /+  /   #    #    +__ +    #   #     Enter     #     \n" },
			{ "     #                                      #                #    +/  +/    #    #    /___/    #   #               #     \n" },
			{ "     #                                      #                ################    ###############   #################     \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                             Select your items via the Arrow                \n" },
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

				if (name == '~' || name == '^')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

				if (name == '+')
					name = char(92);

				//if (name == 'A')
					//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

				if (name == '*')
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

				if (name != ' ') {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					cout << name;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
		}
	}

	void drawItemsInVend(Vending cafe, int depth = 0) {
		for (int i = depth; i < cafe.slots.size() - depth; i++) {

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 8,SHORT(i + 2) });
			cout << "Item: " << cafe.slots[i].name << " Price: $" << cafe.slots[i].price << " Qty: " << cafe.slots[i].qty << endl;
		}
	}
};

int main() {
	cout << "Welcome to VenMach Tech INC." << endl;
	cout << "Please make a selection" << endl;

	bool notDone = true;
	int itemsInVendingMachine = 40;
	Vending cafe;

	for (int i = 0; i < itemsInVendingMachine - cafe.slots.size(); i++) {
		item e("Cake", 1.25, 5);
		cafe.slots.push_back(e);
	}

	while (notDone) {
		int depth = 0;
		string e;
		vector<int> inputs;

		do {
			system("CLS");
			Screen::drawScreen(Screen::Selection());
			Screen::drawItemsInVend(cafe, depth);
			int input;
			cin >> input;

			if (cafe.checkLocation(cafe, input))
				inputs.push_back(input);
			else {
				cout << "Invalid Location" << endl;
				cout << "Please try again" << endl;
			}

			cout << "Would you like to pick more? Y/N" << endl;
			cin >> e;
		} while (e == "Y" || e == "y");


		// start of stuff
		for each (int _item in inputs)
		{
			cafe.displayItemInformation(cafe, _item);
		}
		cout << endl << "Would you like check out?" << endl;


	}

	cout << "Thank you shop again!" << endl;
	getch();
}
