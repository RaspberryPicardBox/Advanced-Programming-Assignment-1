#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
	int total;
	std::list<Item*> orderList;

public:

	void add(int selection);
	void remove(int selection);

	int calculateTotal();
	void printReceipt();

	std::string toString();
};