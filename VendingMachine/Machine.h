#pragma once
#include <vector>
#include "Item.h"

class Machine
{
public:
	double totalMoneys;
	~Machine();
	vector<Item> slots = {};
	Machine();
	void totalMoney();
	void dropItem(Machine *, vector<int>);
	void displayItemInformation(Machine *, vector<int>);
	void dispenceCash(double money = 0);
	void restock();
	void displayError(string e);
	void reset();
	bool checkInput(int);
	bool checkLocation(Machine, int);
};

