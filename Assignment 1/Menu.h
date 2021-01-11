#pragma once
#include "ItemList.h"
#include "Item.h"
#include <string>
#include <vector>


class Menu : ItemList {
public:
	std::vector<Item*> items;
	std::string toString();
	Menu(std::string filePath);
};