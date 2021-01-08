#pragma once
#include "ItemList.h"
#include "Item.h"
#include <string>
#include <vector>


class Menu : ItemList {
public:
	std::vector<Item*> menuList;
	std::string toString();
	Menu(std::string filePath);
};