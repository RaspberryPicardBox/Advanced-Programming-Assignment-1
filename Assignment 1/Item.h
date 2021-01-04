#pragma once
#include <string>

class Item {
	int calories;
	std::string name;
	float price;

public: 
	virtual std::string toString() {

	};
};

class Appetiser : Item {
	bool shareable;
	bool twoForOne;

public:
	std::string toString() {

	};
};

class MainCourse : Item {

};

class Beverage : Item {
	float abd;
	int volume;

public:
	bool isAlcoholic{

	};

	std::string toString() {

	};
};