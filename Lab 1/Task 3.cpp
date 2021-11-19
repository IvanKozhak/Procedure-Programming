#include <iostream>

const double p_aluminium = 0.0282;

double calculateResistance(const double wireLength, const double transverseSection) {
	return p_aluminium*wireLength/transverseSection;
}

int main() {
	std::cout << "Enter length of wire (meters) and transverse section (millimeters):\n";
	
	double wireLength, transverseSection;
	if (!(std::cin >> wireLength) || !(std::cin >> transverseSection)) {
		std::cerr << "Error reading data";
		return 1;
	}
	
	if ((wireLength <= 0) || (transverseSection <= 0)) {
		std::cerr << "Wrong data";
		return 2;
	}
	
	std::cout << "Wire resistance: " << calculateResistance(wireLength, transverseSection) << " Om";
}