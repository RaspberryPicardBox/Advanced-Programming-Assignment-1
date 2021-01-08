#pragma once
#include "ItemList.h"
#include "Item.h"
#include <string>


class Menu : ItemList {
public:
	std::list<Item*> menuList;
	std::string toString();
	Menu(std::string filePath);
};