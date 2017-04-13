
#include "stdafx.h"
#include "Item.h"
#include "Machine.h"
#include "Utils.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <string>
#include <math.h>

#include <windows.h>
#include <mmsystem.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <thread>

using namespace std;

int main() {
	//Initalize programs varibles 
	Machine *cafe = new Machine;
	int depth = 0, input_num;
	char input;
	string input_val;
	vector<int> inputs;

	// Write files contents in to cafe->slots
	Utils::Screen::importVend(cafe);

	// Draw to the screen
	system("CLS");
	Utils::Screen::drawScreen(Utils::Screen::Selection());
	Utils::Screen::drawItemsInVend(cafe);

	do {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(65),SHORT(18) });
		cout << "       ";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(65),SHORT(18) });
		
		// Input
		cin >> input_val;


		try { input_num = stoi(input_val); }
		catch (const std::exception&) { input_num = 1; }


		if (input_num < 100)
			//Print generic error
			Utils::Screen::wrongInfo();

		else
		{
			//convert location to array location
			int  remain = 4 * floor(input_num / 100) - 4 + input_num % 100;
			//Add array location to list of seleected items
			if (inputs.size() < 10 && remain < cafe->slots.size())inputs.push_back(remain - 1);
		}


		//Print your selection to the selected area
		cafe->displayItemInformation(cafe, inputs);
	} while (input_val != " ");

	//change


	getch();
}
