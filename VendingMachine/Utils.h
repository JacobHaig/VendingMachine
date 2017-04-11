#pragma once
#include <string>
#include <vector>
#include "Machine.h"

namespace Utils {
	class Screen {
	public:
		static vector<string> Menu();
		static vector<string> Selection();
		static void drawScreen(vector<string> Map);
		static void drawItemsInVend(Machine *cafe, int &depth, int arrow = 0);
		static void importVend(Machine *cafe);
	};
}