#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

const double x=0.5;
const double y=0.05;
const double z=0.7;

double calculateA() {
	return (x*x*(x+1))/(y-pow(sin(x+z),2));
}

double calculateB() {
	return sqrt(x*y/z)+pow(cos(pow(x+y,2)),2);
}

int main() {
	std::cout   << "Entered constants:\nx = " 
				<< x 
				<< "\ny = " << y 
				<< "\nz = " << z 
				<< "\n\nCalculating results:\na = "
				<< calculateA()
				<< "\nb = " << calculateB();
}