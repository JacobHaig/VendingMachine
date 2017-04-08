
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
	vector<int> inputs;
	int arrow = 0;

	// Write files contents in to cafe->slots
	Utils::Screen::importVend(cafe);

	// Draw to the screen
	system("CLS");
	Utils::Screen::drawScreen(Utils::Screen::Selection());

	do {
		Utils::Screen::drawItemsInVend(cafe, depth, arrow);
		input = _getch();

		if (input == 'w')if (arrow > 0)arrow--;
		if (input == 's')if (arrow < cafe->slots.size() - 1)arrow++;
		if (input == ' ') if (inputs.size() < 10)inputs.push_back(arrow);

		cafe->displayItemInformation(cafe, inputs);
	} while (input != 'p');

	getch();
}
