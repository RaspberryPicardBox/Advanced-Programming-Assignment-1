#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
	float twoForOneTotal = 0;
	bool twoForOneFlag = false;
	std::list<Item*> orderList;

public:

	void add(Item* selection);
	void remove(Item* selection);

	float calculateTotal();
	void printReceipt();

	std::string toString();
};