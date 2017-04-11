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
	void Screen::drawItemsInVend(Machine *cafe, int &depth, int arrow) {
		//if (arrow > 24 + depth) depth++;
		for (int i = depth; i < min(cafe->slots.size(), 24 + depth) - depth; i++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 8 , SHORT(i + 3) });
			if (i == arrow) cout << "*"; else cout << " ";
			cout << "Item: " << cafe->slots[i].name << " Price: $" << cafe->slots[i].price << " Qty: " << cafe->slots[i].qty << endl;
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
}
