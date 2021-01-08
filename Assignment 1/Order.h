#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
	int total;
	std::list<Item*> orderList;

public:

	void add(Item* selection);
	void remove(Item* selection);

	int calculateTotal();
	void printReceipt();

	std::string toString();
};