#pragma once
#include <string>
#include <vector>
#include "Machine.h"

namespace Utils {
	class Screen {
	public:

		int range;
		static vector<string> Menu();
		static vector<string> Selection();
		static void drawScreen(vector<string> Map);
		static void drawItemsInVend(Machine *cafe);
		static void importVend(Machine *cafe);
		static void wrongInfo();
		static void randomize(int, Machine);
	};
}