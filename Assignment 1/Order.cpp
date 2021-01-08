#include "Order.h"
#include "Item.h"
#include <iostream>

void Order::add(Item* selection){
	orderList.push_back(selection);
}

void Order::remove(Item* selection) {
	orderList.remove(selection);
}

int Order::calculateTotal() {
	int total = 0;
	return total;
}

std::string Order::toString() {
	std::string orderOut;

	return orderOut;
}

void Order::printReceipt() {

}