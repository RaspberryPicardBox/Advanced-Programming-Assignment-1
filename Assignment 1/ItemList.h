#pragma once
#include "Item.h"
#include <string>
#include <list>

class ItemList {
public:
	std::list<Item*> items;

	virtual std::string toString() = 0;
};