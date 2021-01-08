#include "Order.h"
#include "Item.h"
#include <iostream>
#include<vector>

void Order::add(Item* selection){
	orderList.push_back(selection);
	std::cout << selection->name << " added to order!\n" << std::endl;
}

void Order::remove(Item* selection) {
	orderList.remove(selection);
	std::cout << selection->name << " removed from order!\n" << std::endl;
}

float Order::calculateTotal() {
	float total = 0;
	int twoForOneItems = 0;

	twoForOneFlag = false;
	twoForOneTotal = 0;

	for (auto& iter : orderList) {
		Item* (*item) = &iter;

		if ((*item)->twoForOne == true) {
			twoForOneItems++;

			if (twoForOneItems > 1) {
				twoForOneFlag = true;
				twoForOneItems = 0;
				total += 3.99;
				twoForOneTotal += 3.99;
			}
		}
		else {
			total += (*item)->price;
		}

	}

	return total;
}

std::string Order::toString() {
	std::string orderOut;
	int iterator = 1;

	float total = calculateTotal();

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
		iterator++;
		orderOut += "\n";
	}

	orderOut += "-------------\n";

	if (twoForOneFlag == true) {
		orderOut += "2-4-1 discount applied! Savings: \x9c" + std::to_string(twoForOneTotal) + "\n";
	}
	
	orderOut += "Total: \x9c" + std::to_string(total) + "\n";

	return orderOut;
}

void Order::printReceipt() {

}