#include <iostream>
#include <stdexcept>

enum Formula : short unsigned int {
	INCREASE_BY_N_TIMES = 1,
	INCREASE_BY_2N_TIMES = 2,
	INCREASE_BY_3N_TIMES = 3
};

void increase_A(const short unsigned int formula, double& A, const double N) {
	switch(formula) {
		case INCREASE_BY_N_TIMES: 
			A = N*A;
			return;
		case INCREASE_BY_2N_TIMES:
			A = 2*N*A;
			return;
		case INCREASE_BY_3N_TIMES:
			A = 3*N*A;
			return;
		default:
			std::cerr << "No such formula";
			throw std::runtime_error("No such formula");
	}
}

int main() {
	std::cout << "Enter A and N:\n";
	
	double A, N;
	if (!(std::cin >> A) || !(std::cin >> N)) {
		std::cerr << "Error reading data";
		return 1;
	}
	
	std::cout << "\nSelect formula:\n1. A = N*A\n2. A = 2N*A\n3. A = 3N*A\n";
	
	short unsigned int user_decision;
	if (!(std::cin >> user_decision)) {
		std::cerr << "Error reading data";
		return 2;
	}
	
	increase_A(user_decision, A, N);
	std::cout << "\nValue of A after formula: " << A;
}