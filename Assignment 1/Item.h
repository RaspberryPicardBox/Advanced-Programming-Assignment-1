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

	virtual std::string toString() { return { name + "," + std::to_string(price) + "," + std::to_string(calories) }; }; // TODO: Return only two decimal places
};

class Appetiser : public Item {
public:
	bool shareable = false;
	bool twoForOne = false;

	std::string toString() {
		return { name + "," + std::to_string(price) + "," + std::to_string(calories) + "," + std::to_string(shareable) + "," + std::to_string(twoForOne) };
	};
};

class MainCourse : public Item {

};

class Beverage : public Item {
public:
	float abv = 0;
	int volume = 0;

	bool isAlcoholic{};

	std::string toString() {
		return { name + "," + std::to_string(price) + "," + std::to_string(calories) + "," + std::to_string(volume) + "," + std::to_string(abv) };
	};
};