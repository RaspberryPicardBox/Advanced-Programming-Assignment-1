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



	order.add(menu.menuList[0]);
	order.add(menu.menuList[5]);
	order.add(menu.menuList[10]);

}