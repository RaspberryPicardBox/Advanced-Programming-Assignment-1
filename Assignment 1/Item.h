#pragma once
#include <string>

class Item {
public: 
	int calories;
	std::string name;
	float price;

	virtual std::string toString() { return { name + "," + std::to_string(price) + "," + std::to_string(calories) }; };
};

class Appetiser : public Item {
public:
	bool shareable;
	bool twoForOne;

	std::string toString() {
		return { name + "," + std::to_string(price) + "," + std::to_string(calories) + "," + std::to_string(shareable) + "," + std::to_string(twoForOne) };
	};
};

class MainCourse : public Item {

};

class Beverage : public Item {
public:
	float abv;
	int volume;

	bool isAlcoholic{};

	std::string toString() {
		return { name + "," + std::to_string(price) + "," + std::to_string(calories) + "," + std::to_string(volume) + "," + std::to_string(abv) };
	};
};