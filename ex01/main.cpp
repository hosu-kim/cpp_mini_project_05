#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	// Normal signing case
	try {
		std::cout << "--- Test 1: Normal Sign ---" << std::endl;
		Bureaucrat boss("The Boss", 1);
		AForm f1("Top Secret Document", 10, 20);

		std::cout << f1 << std::endl;
		boss.signForm(f1);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n------------------------------\n" << std::endl;

	// refusal case
	try {
		std::cout << "--- Test 2: Grade Too Low to Sign ---" << std::endl;
		Bureaucrat intern("The Intern", 150);
		AForm f2("Important paper", 50, 50);

		std::cout << f2 << std::endl;
		intern.signForm(f2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// making an error
	std::cout << "\n------------------------------\n" << std::endl;

	try {
		std::cout << "--- Test 3: Invalid Form Creation ---" << std::endl;
		AForm f3("Impossible Form", 0, 151);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}