#include "Item.h"
#include<sstream>
#include<iomanip>

std::string Item::toString() {
	std::stringstream priceFixed;
	priceFixed.precision(3);
	priceFixed << price;

	std::stringstream caloriesFixed;
	caloriesFixed.precision(3);
	caloriesFixed << calories;

	return { name + ": " + '\x9c' + priceFixed.str() + ", " + caloriesFixed.str() + " cal " };
}

bool Beverage::isAlcoholic() {
	if (abv > 0) {
		return true;
	}
	else {
		return false;
	}
}