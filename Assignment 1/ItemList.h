#pragma once
#include "Item.h"
#include <string>
#include <list>
#include <iterator>

class ItemList {
public:
	std::list<Item*> items;
	bool flag;
	virtual std::string toString() = 0;

	std::list<Item*> getItems();
	void setItems(std::list<Item*> list);
};