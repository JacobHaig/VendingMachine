#pragma once

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

class vending {
public:
	vector<item> slots = {};
	vending();
	void dropItem();
	void displayItemInformation(vending, vector<int>);
	void dispenceCash();
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(vending, int);
};
class item {
public:
	item(string, double, int);
	string name;
	double price;
	int qty;
};
