#include "Menu.h"
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

Menu :: Menu(std::string filePath) {

	std::string type;
	std::string name;
	float price;
	int calories;
	bool shareable;
	bool twoForOne;
	int volume;
	int abv;

	

	std::ifstream menuFile(filePath);
	std::string line;
	std::string word;

	if (menuFile.good()) {
		while (std::getline(menuFile, line)) {
			std::istringstream stringStream(line);
			
			int iterations = 0;

			while (std::getline(stringStream, word, ',')) {

				switch (iterations) {
				case 0:
					type = word;
					std::cout << type << std::endl;
					break;
				case 1:
					name = word;
					std::cout << name << std::endl;
					break;
				case 2:
					price = std::stof(word);
					std::cout << price << std::endl;
					break;
				}

				iterations++;
			}
		}
	}
}