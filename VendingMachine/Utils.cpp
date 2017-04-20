#include "stdafx.h"
#include "Utils.h"
#include "Item.h"
#include "Machine.h"

#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <vector>
#include <ctime>

#include <stdexcept>

using namespace std;

namespace Utils {
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
	}// Not used

	vector<string> Screen::Selection() { // returns Map1
		vector<string> Map = {
			{ "                                                                                                                         \n" },
			{ "     ########################################                      Select your items by typing the ID here:              \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                            Once you are done, type 'done'                  \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                                                                            \n" },
			{ "     #                                      #                #######################################################     \n" },
			{ "     #                                      #                #                                                     #     \n" },
			{ "     #                                      #                #                                                     #     \n" },
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
	}// Map of Selection screen

	void Screen::drawScreen(vector<string> Map) {
		//This is the rendering function. It draws the vector<string> maps to the screen
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

	void Screen::drawItemsInVend(Machine *cafe) {// Draws all the Items that are added to the slots of Machine
		for (int i = 0; i < min(cafe->slots.size(), 24); i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 7 , SHORT(i + 3) });
			if (i < 4) cout << 10 << i + 1;
			else if (i < 8) cout << 20 << i - 4 + 1;
			else if (i < 12) cout << 30 << i - 8 + 1;
			else if (i < 16) cout << 40 << i - 12 + 1;
			else if (i < 20) cout << 50 << i - 16 + 1;
			else cout << 60 << i - 20 + 1;

			cout << ": " << cafe->slots[i].name << " $" << cafe->slots[i].price << " Qty: " << cafe->slots[i].qty << endl;
		}
	}

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
	}// Puts all the Items from Items.txt into cafe.txt

	void Screen::wrongInfo() {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(70),SHORT(10) });

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Wrong Information Please Try Again.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
	}

	void Screen::randomize(int range) {
		int random;
		srand(time(0));
		random = rand() % range;
	}
}