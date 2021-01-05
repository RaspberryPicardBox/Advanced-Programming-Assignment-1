#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
	int total;

public:

	void add(int selection) {};
	void remove(int selection) {};

	int calculateTotal() {};

	std::string printReceipt() {};

	std::string toString() {};
};