#pragma once
#include "Item.h"
#include <string>
#include <vector>

class ItemList {
public:
	std::vector<Item*> items;
	virtual std::string toString() = 0;
};