
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

#include "Vending.h"
#include "Screen.h"

using namespace std;


int main() {
	//cout << "Welcome to VenMach Tech INC." << endl;
	//cout << "Please make a selection" << endl;

	bool notDone = true;
	int itemsInVendingMachine = 40;
	vending cafe;

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