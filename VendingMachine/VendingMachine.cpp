
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

	Machine *cafe = new Machine;
	int depth = 0;
	char input;
	vector<int> inputs;
	int arrow = 3;


	Item e("Pie", 1.85, 3);
	cafe->slots.push_back(e);
	//delete e;
	Item r("Soda", 1.5, 8);
	cafe->slots.push_back(r);


	int itemsInVendingMachine = 24 - cafe->slots.size();
	for (int i = 0; i < itemsInVendingMachine; i++) {
		Item e("Cake", 1.25, 5);
		cafe->slots.push_back(e);
	}


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

	cout << "Thank you shop again!" << endl;
	getch();
}
