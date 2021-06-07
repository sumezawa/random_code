/* C++ stringstream data type checker */

#include <iostream>
#include <string>
#include <sstream>

void streamhandler(std::istringstream& input);

int main() {
	std::istringstream sample("plopskiy 14 23 9 bubzskij 90 59 69 69 yessirskiy 13");
	streamhandler(sample); // should print out only the integers

	return 0;
}

void streamhandler(std::istringstream& input) {
	uint16_t num = 0;
	// does not work: uint8_t
	// work: int, double, uint16_t
	while(input >> num || !input.eof()) {
		if(input.fail()) {
			input.clear();
			std::string dummy;
			input >> dummy;
			continue;
		}
		std::cout << num << std::endl;
	}
}
