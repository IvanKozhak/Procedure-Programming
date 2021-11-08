#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

const double a = 1.5;

double calculateFunction(const double x) {
	const double ax = a*x;
	
	if (ax<=0) {
		std::cerr << "Wrong data";
		throw std::runtime_error("Wrong data");
	}
	
	if (x<1/a) return ax-log10(ax);
	return ax+log10(ax);
}

int main() {
	std::cout << "Enter x: ";
	
	double x;
	if (!(std::cin >> x)) {
		std::cerr << "Error reading data";
		return 1;
	}
	
	std::cout << "\nFunction result: " << calculateFunction(x);
}