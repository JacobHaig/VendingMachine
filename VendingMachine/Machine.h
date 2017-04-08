#pragma once
#include <vector>
#include "Item.h"


class Machine
{
public:

	~Machine();
	vector<Item> slots = {};
	Machine();
	void dropItem();
	void displayItemInformation(Machine, vector<int>);
	void dispenceCash();
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(Machine, int);
};

