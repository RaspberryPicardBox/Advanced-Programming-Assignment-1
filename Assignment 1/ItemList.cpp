#include "ItemList.h"

std::list<Item*> ItemList::getItems() {
	return this->items;
}

void ItemList::setItems(std::list<Item*> list) {
	this->items = list;
}