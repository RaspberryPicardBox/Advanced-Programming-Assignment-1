#pragma once
#include "ItemList.h"
#include "Item.h"
#include <string>


class Menu : ItemList {
	std::list<Item*> menuList;
public:
	std::string toString();
	Menu(std::string filePath);
};