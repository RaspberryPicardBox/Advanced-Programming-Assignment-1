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



	order.add(menu.menuList[1]);
	order.add(menu.menuList[2]);
	order.add(menu.menuList[3]);

	std::cout << order.toString() << std::endl;

	order.remove(menu.menuList[2]);

	std::cout << order.toString() << std::endl;

}