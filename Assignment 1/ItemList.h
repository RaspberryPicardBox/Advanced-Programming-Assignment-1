#pragma once
#include "Item.h"
#include <string>
#include <list>
#include <iterator>

class ItemList {
public:
	std::list<Item*> items; // TODO: Possibly create seperate lists for different types of items? Would allow for auto-sorting of menu
	virtual std::string toString() = 0;

	std::list<Item*> getItems();
	void setItems(std::list<Item*> list);
};