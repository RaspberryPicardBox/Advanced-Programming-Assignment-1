#pragma once
#include "ItemList.h"
#include <string>
#include <list>

class Order : ItemList {
	int total;

public:
	int calculateTotal() {};

	std::string printReceipt() {};

	std::string toString() {};
};