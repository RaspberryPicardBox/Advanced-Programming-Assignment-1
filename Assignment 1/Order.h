#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
public:
	double total = 0;
	double twoForOneTotal = 0;
	bool twoForOneFlag = false;

	std::vector<Item*> items;

	void add(Item* selection);
	void remove(Item* selection);

	float calculateTotal();
	void printReceipt();

	std::string toString();
};