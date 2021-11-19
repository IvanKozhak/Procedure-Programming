#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

const double x_start = 0.2;
const double x_end = 1;
const double step= 0.1;
const double accuracy= 0.0001;

double y(const double x) {
	if (x<=0) throw std::runtime_error("No value");
	return log(x)/2;
}

double getElementByIndex(const double x, const size_t n) {
	return (1/(double)(2*n+1))*pow((x-1)/(x+1), 2*n+1);
}

double getSummWithAccuracy(const double x, const double accuracy) {
	double result=0;
	double cur = getElementByIndex(x, 0);
	size_t i;
	for (i=0; fabs(cur) >= accuracy; ++i, cur=getElementByIndex(x, i))
		result+=cur;
	result+=getElementByIndex(x, ++i);
	return result;
}

int main() {
	std::cout << std::fixed << std::setw(10) << 'X' << " | " << std::setw(10) << "Y" << " | " << std::setw(10) << "Summ\n";
	for (double x = x_start; x<=x_end; x+=step) 
		try{
			const double _y = y(x);
			std::cout << std::setw(10) << x << " | " << std::setw(10) << _y << " | " << std::setw(10) << getSummWithAccuracy(x, accuracy) << '\n';
		}catch(...) {
			std::cout << std::setw(10) << x << " | " << std::setw(10) << "No value" << " | " << std::setw(10) << '-' << '\n';
		}
}