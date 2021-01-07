#include "Order.h"
#include "Item.h"
#include <iostream>

void Order::add(int selection){
	int iterator = 1;

	for (auto& iter : ItemList::getItems()) {
		Item(*item) = iter;
		if (iterator == selection) {
			orderList.push_back(item);
			break;
		}
		iterator++;
	}
}

void Order::remove(int selection) {

}

int Order::calculateTotal() {
	return 0;
}

std::string Order::toString() {
	std::string orderOut;

	int iterator = 1;
	for (auto& iter : this->orderList) {
		Item(*item) = iter;

		bool shareable = (*item).shareable;
		bool twoForOne = (*item).twoForOne;

		int volume = (*item).volume;
		float abv = (*item).abv;

		if ((*item).type == "a") {
			orderOut += "(" + std::to_string(iterator + 1) + ") " + (*item).name + ": " + '\x9c' + std::to_string((*item).price) + ", " + std::to_string((*item).calories) + " cal ";

			if (shareable) {
				orderOut += "(shareable) ";
			}
			if (twoForOne) {
				orderOut += "(2-4-1) ";
			}

			orderOut += "\n";
		}
		else if ((*item).type == "m") {
			orderOut += "(" + std::to_string(iterator + 1) + ") " + (*item).name + ": " + '\x9c' + std::to_string((*item).price) + ", " + std::to_string((*item).calories) + " cal\n";
		}
		else if ((*item).type == "b") {
			orderOut += "(" + std::to_string(iterator + 1) + ") " + (*item).name + ": " + '\x9c' + std::to_string((*item).price) + ", " + std::to_string((*item).calories) + " cal ";

			if (abv > 0) {
				orderOut += "(" + std::to_string(volume) + "ml, " + std::to_string(abv) + "% abv)\n";
			}
			else {
				orderOut += "(" + std::to_string(volume) + "ml)\n";
			}
		}


		iterator++;
	}
	return orderOut;
}

void Order::printReceipt() {

}