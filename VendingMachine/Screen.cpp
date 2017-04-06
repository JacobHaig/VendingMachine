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

#include "Screen.h"
#include "Vending.h"

using namespace std;


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

	void drawItemsInVend(vending cafe, int depth = 0, int arrow = 0) {

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