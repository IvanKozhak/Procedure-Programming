#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>

#define X_START_DEFAULT 0
#define X_END_DEFAULT 1
#define STEP_DEFAULT 0.1

double calculateFunction(const double x) {
	if ((1-x)<0) throw std::runtime_error("No value in this point");
	const double _sqrt = sqrt(1-x);
	
	return _sqrt-cos(_sqrt);
}

int main() {
	std::cout << "Enter bottom and top of interval:\n";
	
	double x;
	if (!(std::cin >> x)) {
		std::cerr << "Error reading data; Assuming as default\n";
		x = X_START_DEFAULT;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	double x_end;
	if (!(std::cin >> x_end)) {
		std::cerr << "Error reading data; Assuming as default\n";
		x_end = X_END_DEFAULT;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	double step;
	std::cout << "Enter step:\n";
	if (!(std::cin >> step) || (step==0)) {
		std::cerr << "Error reading data; Assuming as default\n";
		step = STEP_DEFAULT;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	std::cout << std::fixed << std::setw(5) << 'X' << " | " << std::setw(10) << "Y\n";
	
	size_t i_max = (size_t)(round((fabs(x)+fabs(x_end))/fabs(step)));
	for (size_t i = 0; i<=i_max; ++i) {
		try{
			const double y = calculateFunction(x);
			std::cout << std::setw(5) << x << " | " << std::setw(10) << y << '\n';
		}catch(...) {
			std::cout << std::setw(5) << x << " | " << std::setw(10) << "No solution\n";
		}
		x+=step;
	}
}