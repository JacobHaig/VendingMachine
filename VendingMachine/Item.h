#pragma once

#include <string>

using namespace std;

class Item
{
public:
	Item(string, double, int);
	~Item();
	string name;
	double price;
	int qty;
};

