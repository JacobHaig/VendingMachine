
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
	for (int j = 0; j < 1; j++) {
		for (int i = j; i < inputs.size() % 6; i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70 + 15 * j),SHORT(i + 12) });
			cout << i + i*j + 1 << ". " << cafe.slots[inputs[i + i*j]].name << "  - " << cafe.slots[inputs[i + i*j]].price << endl;
		}
	}
}

void Vending::dispenceCash() {}
void Vending::restock() {}
void Vending::displayError(string e) {}
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

	void drawItemsInVend(Vending cafe, int depth = 0, int arrow = 0) {

		for (int i = depth; i < cafe.slots.size(); i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 8,SHORT(i + 2) });
			if (i == arrow) std::cout << '*'; else std::cout << ' ';
			std::cout << "Item: " << cafe.slots[i].name << " Price: $" << cafe.slots[i].price << " Qty: " << cafe.slots[i].qty << endl;
		}

	}

	char getInput() {
		char key = _getch();
		return key;
	}
};

int main() {
	//cout << "Welcome to VenMach Tech INC." << endl;
	//cout << "Please make a selection" << endl;

	bool notDone = true;
	int itemsInVendingMachine = 40;
	Vending cafe;

	item e("Casssske", 1.25, 5);
	cafe.slots.push_back(e);

	for (int i = 0; i < itemsInVendingMachine - cafe.slots.size(); i++) {
		item e("Cake", 1.25, 5);
		cafe.slots.push_back(e);
	}

	while (notDone) {
		int depth = 0;
		int arrow = 3;
		string e;
		char input = 'p';
		vector < int > inputs;
		system("CLS");
		Screen::drawScreen(Screen::Selection());


		do {

			//Screen::drawScreen(Screen::Selection());
			Screen::drawItemsInVend(cafe, depth, arrow);

			input = Screen::getInput();
			if (input == 'w')
				if (!(arrow <= 0)) arrow -= 1;
			if (input == 's')
				if (!(arrow >= cafe.slots.size() - 1)) arrow += 1;
			if (input == ' ') {
				inputs.push_back(arrow);
				cafe.displayItemInformation(cafe, inputs);
			}

			/*
			if (cafe.checkLocation(cafe, input))
				inputs.push_back(input);
			else {
				cout << "Invalid Location" << endl;
				cout << "Please try again" << endl;
			}

			cout << "Would you like to pick more? Y/N" << endl;
			cin >> e;
			for each(int _item in inputs) {
				cafe.displayItemInformation(cafe, inputs);
			}*/
		} while (input != 'p');

		// start of stuff
		/*for each(int _item in inputs) {
			cafe.displayItemInformation(cafe, _item);
		}*/
		cout << endl << "Would you like check out?" << endl;

	}

	cout << "Thank you shop again!" << endl;
	getch();
}