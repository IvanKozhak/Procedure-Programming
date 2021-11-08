#include <iostream>

bool hasPositiveSumm(const double number1, const double number2, const double number3) {
	if ( ((number1+number2)>0) || ((number1+number3)>0) || ((number2+number3)>0)) return true;
	return false;
}

int main() {
	std::cout << "Enter three numbers:\n";
	double number1, number2, number3;
	
	if (!(std::cin >> number1) || !(std::cin >> number2) || !(std::cin >> number3)) { 
		std::cerr << "Error reading data";
		return 1;
	}
	
	hasPositiveSumm(number1, number2, number3) ? std::cout << "\nNumbers list has positive summ" : std::cout << "Numbers list doesnt have positive summ";
}