#pragma once
#include "Item.h"
#include <string>
#include <list>
#include <iterator>
#include <vector>

class ItemList {
public:
	std::vector<Item*> items;
	bool flag;
	virtual std::string toString() = 0;

	std::vector<Item*> getItems();
	void setItems(std::vector<Item*> list);
};