#include "stdafx.h"
#include "Item.h"
#include <string>


Item::Item(string n, double p, int q) {
	name = n;
	price = p;
	qty = q;
}
Item::~Item() {};