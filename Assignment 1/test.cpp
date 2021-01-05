#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	Menu menu = Menu("menu.csv");
	Order order;

	std::cout << menu.toString() << std::endl;

	order.add(2);
	order.add(5);
	order.add(8);

	std::cout << std::endl << order.toString() << "Here" << std::endl;
}