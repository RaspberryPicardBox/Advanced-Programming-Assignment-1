#pragma once
#include "Item.h"
#include <string>
#include <list>

class ItemList {
	std::list<Item*> items;

	virtual std::string toString() {

	};
};