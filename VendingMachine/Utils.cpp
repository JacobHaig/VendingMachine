#include "stdafx.h"
#include "Utils.h"
#include "Item.h"
#include "Machine.h"

#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <vector>

#include <stdexcept>

using namespace std;

namespace Utils {
	// Not used 
	vector<string> Screen::Menu() { // returns Map1 
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

	// Map of Selection screen
	vector<string> Screen::Selection() { // returns Map1 
		vector<string> Map = {
			{ "                                                                                                                         \n" },
			{ "     ########################################                ################    ###############   #################     \n" },
			{ "     #                                      #                #  +        /  #    #    /'__/    #   #     Space     #     \n" },
			{ "     #                                      #                #   +  /+  /   #    #    +__ +    #   #      to       #     \n" },
			{ "     #                                      #                #    +/  +/    #    #    /___/    #   #     select    #     \n" },
			{ "     #                                      #                ################    ###############   #################     \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                             Enter the item number to select                \n" },
			{ "     #                                      #                                 the Item from the list                     \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                #######################################################     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #######################################################     \n" },
			{ "     #                                      #                 #              #                   #                #      \n" },
			{ "     #                                      #                 ################                   ##################      \n" },
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

	//This is the rendering function. It draws the vector<string> maps to the screen
	void Screen::drawScreen(vector<string> Map) {
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

	// Draws all the Items that are added to the slots of Machine
	void Screen::drawItemsInVend(Machine *cafe) {
		//if (arrow > 24 + depth) depth++;
		for (int i = 0; i < min(cafe->slots.size(), 24); i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7 , SHORT(i + 3) });
			if (i < 4) cout << 10 << i + 1;
			else if (i < 8) cout << 20 << i - 4 + 1;
			else if (i < 12) cout << 30 << i - 8 + 1;
			else if (i < 16) cout << 40 << i - 12 + 1;
			else cout << 50 << i - 16 + 1;

			cout << ": " << cafe->slots[i].name << " $" << cafe->slots[i].price << " Qty: " << cafe->slots[i].qty << endl;
		}
	}

	// Puts all the Items from Items.txt into cafe.txt
	void Screen::importVend(Machine *cafe) {
		ifstream file("items.txt");
		Item items();
		string str;
		while (getline(file, str)) {
			string a;
			double b;
			int c;
			file >> a >> b >> c;
			Item items(a, b, c);
			cafe->slots.push_back(items);
		}
		file.close();
	}

	void Screen::wrongInfo() {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70),SHORT(10) });

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Wrong Information Please Try Again.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
	}

	

	void Screen::Dispense(double M, int C, int Q, int D, int N, int P)
	{
		int credit = money * 100;
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
		cout << "quarters:" << quarter << endl;
		cout << "dimes:" << dime << endl;
		cout << "nickels:" << nickel << endl;
		cout << "pennies:" << penny << endl;
		_getch();
	}

}
