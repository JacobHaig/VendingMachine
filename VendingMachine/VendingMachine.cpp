
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
	int depth = 0;
	char input;
	int input_num;
	vector<int> inputs;
	int arrow = 0;

	// Write files contents in to cafe->slots
	Utils::Screen::importVend(cafe);

	// Draw to the screen
	system("CLS");
	Utils::Screen::drawScreen(Utils::Screen::Selection());

	do {
		Utils::Screen::drawItemsInVend(cafe);
		//input = _getch();
		cin >> input_num;

		//Inputs and condistions
		//if (input == 'w' && arrow > 0) arrow--;
		//if (input == 's' && arrow < cafe->slots.size() - 1) arrow++;
		//if (input == ' ' && inputs.size() < 10) inputs.push_back(arrow);

		int  remain = 4 * floor(input_num / 100) - 4 + (input_num % 100);
		inputs.push_back(remain - 1);



		//Print your selection to the selected area
		cafe->displayItemInformation(cafe, inputs);
	} while (input_num != '0');

	getch();
}
