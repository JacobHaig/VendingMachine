
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
	Machine *cafe = new Machine;//Initalize programs varibles 
	int depth = 0, input_num;
	char input;
	string input_val;
	vector<int> inputs;

	Utils::Screen::importVend(cafe);// Write files contents in to cafe->slots

	system("CLS");// Draw to the screen
	Utils::Screen::drawScreen(Utils::Screen::Selection());
	Utils::Screen::drawItemsInVend(cafe);

	do {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(65),SHORT(18) });
		cout << "       ";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(65),SHORT(18) });
		cin >> input_val;// Input

		try { input_num = stoi(input_val); }
		catch (const std::exception&) { input_num = 1; }
		if (input_num < 100)
			Utils::Screen::wrongInfo();//Print generic error
		else
		{
			int  remain = 4 * floor(input_num / 100) - 4 + input_num % 100;//convert location to array location
			if (inputs.size() < 10 && remain - 1 < cafe->slots.size())inputs.push_back(remain - 1);//Add array location to list of seleected items
		}

		cafe->displayItemInformation(cafe, inputs);//Print your selection to the selected area
	} while (input_val != " ");

	Utils::Screen::drawScreen(Utils::Screen::Menu());
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(65),SHORT(18) });
	cout << "Enter your payment type. Credit/Debt/Cash :";
	string str;

	do
	{
		cin >> str;
		if (str == "Cash" &&str == "cash"&&str == "Credit"&&str == "credit"&&str == "debt"&&str == "Debt")
		{
			if (str == "Credit"&&str == "credit"&&str == "debt"&&str == "Debt")
				cout << "dispence";
			else
				
			//change
		}
		else
			str = "NOPE";

	} while (str == "NONE");

	getch();
}
