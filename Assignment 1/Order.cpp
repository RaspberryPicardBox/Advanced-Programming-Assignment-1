#include "Order.h"
#include "Item.h"
#include <iostream>
#include<vector>
#include <fstream>

void Order::add(Item* selection){
	orderList.push_back(selection);
	std::cout << "\n" << selection->name << " added to order!\n" << std::endl;
}

void Order::remove(Item* selection) {
	orderList.remove(selection);
	std::cout << "\n" << selection->name << " removed from order!\n" << std::endl;
}

float Order::calculateTotal() {
	double localTotal = 0;
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
				localTotal += 3.99;
				twoForOneTotal += 3.99;
			}
		}
		else {
			localTotal += (*item)->price;
		}

	}

	total = localTotal;

	return localTotal;
}

std::string Order::toString() {
	std::string orderOut;
	int iterator = 1;

	double total = calculateTotal();

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

	return orderOut;
}

void Order::printReceipt() {
	std::ofstream outputFile("receipt.txt");

	outputFile << toString();

	if (twoForOneFlag == true) {
		outputFile << "Savings: \x9c" + std::to_string(twoForOneTotal) + "\n";
	}

	outputFile << "Total: \x9c" + std::to_string(total);

	outputFile.close();
}