#include <iostream>

size_t calculateFactorial(const size_t x) {
	size_t result = 1;
	for (size_t i=2; i<=x; ++i) result*=i;
	return result;
}

double getElementByIndex(const size_t k) {
	return k/(double)calculateFactorial(k+1);
}

int main() {
	std::cout << "Select programm:\na) Summ of first n elemetns\nb) Summ of all elements bigger than e\n";
	
	char user_decision;
	if (!(std::cin >> user_decision)) {
		std::cerr << "Error reading data";
		return 1;
	}
	
	switch(user_decision) {
		case 'a':
		{
			std::cout << "\nEnter elements amount:\n";
			long long elementsAmount;
			if (!(std::cin >> elementsAmount) || (elementsAmount < 0)){
				std::cerr << "Error reading data";
				return 2;
			}
			
			double result=0;
			for (size_t i=1; i<=(size_t)elementsAmount; ++i) result+=getElementByIndex(i);
			std::cout << "\nSumm of first " << elementsAmount << " elemnts: " << result;
			
			break;
		}
		case 'b':
		{
			std::cout << "\nEnter e:\n";
			double e;
			if (!(std::cin >> e)) {
				std::cerr << "Error reading data";
				return 3;
			}
			
			double result=0;
			double cur=getElementByIndex(1);
			for (size_t i=1; cur >= e; ++i, cur=getElementByIndex(i))
				result+=cur;
			
			std::cout << "\nSumm of all elements bigger than " << e << ": "<< result;
			
			break;
		}
		default:
			std::cerr << "No such programm";
			return 4;	
	}
}