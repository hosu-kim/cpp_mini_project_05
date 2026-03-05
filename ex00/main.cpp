#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Top Officer", 1);
		std::cout << b1 << std::endl;

		b1.decrementGrade();
		std::cout << "After decrement: " << b1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	try {
		Bureaucrat b2("The God", 0);
	} catch (std::exception &e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	try {
		Bureaucrat b3("Worker", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
