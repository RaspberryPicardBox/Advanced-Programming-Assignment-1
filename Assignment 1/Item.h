#pragma once
#include <string>

class Item {
public: 
	int calories = 0;
	std::string name;
	float price = 0;

	bool shareable;
	bool twoForOne;

	float abv;
	int volume;

	std::string type;

	std::string toString() { return { name + ": " + '\x9c' + std::to_string(price) + ", " + std::to_string(calories) + " cal " }; };
};

class Appetiser : public Item {
public:
	bool shareable = false;
	bool twoForOne = false;

};

class MainCourse : public Item {
};

class Beverage : public Item {
public:
	float abv = 0;
	int volume = 0;

	bool isAlcoholic{};

};