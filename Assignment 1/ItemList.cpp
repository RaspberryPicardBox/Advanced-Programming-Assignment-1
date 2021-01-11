#include "ItemList.h"

std::vector<Item*> ItemList::getItems() {
	return this->items;
}

void ItemList::setItems(std::vector<Item*> list) {
	this->items = list;
}