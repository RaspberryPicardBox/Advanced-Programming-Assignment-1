#include "Order.h"
#include "Item.h"
#include <iostream>
#include<vector>
#include <fstream>

void Order::add(Item* selection){
	items.push_back(selection);
	std::cout << "\n" << selection->name << " added to order!\n" << std::endl;
}

void Order::remove(Item* selection) {
	int loopIt = 0;
	for (auto iter : items) {
		Item* (*item) = &iter;

		if ((*item) == selection) {
			items.erase(items.begin() + loopIt);
			break;
		}
		loopIt++;
	}
	std::cout << "\n" << selection->name << " removed from order!\n" << std::endl;
}

float Order::calculateTotal() {
	double localTotal = 0;
	int twoForOneItems = 0;
	std::vector<double> twoForOncePrices{};

	twoForOneFlag = false;
	twoForOneTotal = 0;

	for (auto& iter : items) {
		Item* (*item) = &iter;

		if ((*item)->twoForOne == true) {
			twoForOneItems++;
			twoForOncePrices.push_back((*item)->price);

			if (twoForOneItems > 1) {
				twoForOneFlag = true;
				twoForOneItems = 0;
				if (twoForOncePrices[0] < twoForOncePrices[1]) { // Checking to see which of the two products is the cheapest
					localTotal += twoForOncePrices[0];
					twoForOneTotal += twoForOncePrices[0];
				}
				else {
					localTotal += twoForOncePrices[1];
					twoForOneTotal += twoForOncePrices[1];
				}
				twoForOncePrices.clear();
			}
		}
		else {
			localTotal += (*item)->price;
		}

	}

	total = localTotal; // Updating the global total variable for access outside of being called again

	return localTotal;
}

std::string Order::toString() {
	std::string orderOut;
	int iterator = 1;

	double total = calculateTotal();

	orderOut += "===== Checkout =====\n";

	for (auto& iter : items) {
		Item* (*item) = &iter;

		orderOut += '(' + std::to_string(iterator) + ')' + " " + (*item)->toString();


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
	auto orderString = toString();

	std::string line;

	for (int i = 0; i <= orderString.length(); i++) { // Recplacing the escape character used within the C++ console with a standard Unicode symbol
		if (orderString[i] == '\x9c') {
			orderString[i] = '£';
		}
	}

	outputFile << orderString;

	if (twoForOneFlag == true) {
		outputFile << "Savings: £" + std::to_string(twoForOneTotal) + "\n";
	}

	outputFile << "Total: £" + std::to_string(total);

	outputFile.close();
}