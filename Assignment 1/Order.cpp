#include "Order.h"
#include "Item.h"
#include <iostream>

void Order::add(Item* selection){
	orderList.push_back(selection);
	std::cout << selection->name << " added to order!" << std::endl;
}

void Order::remove(Item* selection) {
	orderList.remove(selection);
	std::cout << selection->name << " removed from order!" << std::endl;
}

int Order::calculateTotal() {
	int total = 0;
	return total;
}

std::string Order::toString() {
	std::string orderOut;
	int iterator = 0;

	orderOut += "===== Checkout =====\n";

	for (auto& iter : orderList) {
		Item* (*item) = &iter;

		orderOut += '(' + std::to_string(iterator) + ')' + " " + (*item)->name + ": " + '\x9c' + std::to_string((*item)->price) + ", " + std::to_string((*item)->calories) + " cal";

		if ((*item)->shareable == true) {
			orderOut += " (shareable)";
		}
		if ((*item)->twoForOne == true) {
			orderOut += " (2-4-1)";
		}
		if ((*item)->volume > 0) {
			orderOut += "(" + std::to_string((*item)->volume) + " ml";
			if ((*item)->abv > 0) {
				orderOut += ", " + std::to_string((*item)->abv) + "% abv)";
			}
			else {
				orderOut += ")";
			}
		}

		orderOut += "\n";

		iterator++;
	}

	orderOut += "-------------";

	return orderOut;
}

void Order::printReceipt() {

}