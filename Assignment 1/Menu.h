#pragma once
#include "ItemList.h"
#include <string>


class Menu : ItemList {

public:
	std::string toString() { return "done"; };
	
	Menu(std::string filePath);
};