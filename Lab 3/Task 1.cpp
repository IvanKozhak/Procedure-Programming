#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

const double x_start = 0;
const double x_end = 2;
const double step= 0.1;

double calculateFunction(const double x) {
	if ((1-x)<0) throw std::runtime_error("No value in this point");
	const double _sqrt = sqrt(1-x);
	
	return _sqrt-cos(_sqrt);
}

int main() {
	std::cout << std::setw(5) << 'X' << " | " << std::setw(10) << "Y\n";
	for (double x = x_start; x<=x_end; x+=step) 
		try{
			const double y = calculateFunction(x);
			std::cout << std::setw(5) << x << " | " << std::setw(10) << y << '\n';
		}catch(...) {
			std::cout << std::setw(5) << x << " | " << std::setw(10) << "No solution\n";
		}
}