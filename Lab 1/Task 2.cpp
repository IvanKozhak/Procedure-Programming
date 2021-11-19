#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

double calculateSideC(const double sideA, const double sideB, const double angle) {
	return sqrt(sideA*sideA+sideB*sideB-2*sideA*sideB*cos(angle));
}

double calculateSquare(const double sideA, const double sideB, const double angle) {
	return ((sideA*sideB*sin(angle))/2);
}

double calculateNearCircleRadius(const double sideA, const double sideB, const double sideC) {
	const double p = (sideA+sideB+sideC)/2;
	return sideA*sideB*sideC/(4*sqrt(p*(p-sideA)*(p-sideB)*(p-sideC)));
}

int main() {
	std::cout << "Enter two sides of triangle and angle between them:\n";
	
	double sideA, sideB, angle;
	if (!(std::cin >> sideA) || !(std::cin >> sideB) || !(std::cin >> angle)) { 
		std::cerr << "Error reading data";
		return 1;
	}
	if( (sideA<=0) || (sideB<=0) || (angle <=0) ) {
		std::cerr << "Wrong data";
		return 2;
	}
	
	angle *= M_PI/180;
	
	
	double sideC = calculateSideC(sideA ,sideB, angle);
	std::cout   << "\nThird side: " << sideC
				<< "\nSquare of triangle: " << calculateSquare(sideA, sideB, angle)
				<< "\nRadius of circumscribed circle of trinagle: " << calculateNearCircleRadius(sideA, sideB, sideC);
	
}