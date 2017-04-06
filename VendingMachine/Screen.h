#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

namespace Screen {
	vector<string> Menu();
	vector<string> Selection();
	void drawScreen(vector<string> Map);
	void drawItemsInVend(vending cafe, int depth = 0, int arrow = 0);
	char getInput();
}
