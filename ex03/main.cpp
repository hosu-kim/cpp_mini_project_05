#include "Intern.hpp"

int	main() {
	Intern	someRandomIntern;
	AForm*	rrf;

	std::cout << "[Test 1: Valid Form]" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		std::cout << "Form name: " << rrf->getName() << std::endl;
		delete rrf;
	}
	std::cout << "---------------------------------------" << std::endl;

	std::cout << "[Test 2: Valid Form]" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (rrf) { delete rrf; }

	std::cout << "---------------------------------------" << std::endl;

	std::cout << "[Test 3: Invalid Form]" << std::endl;
	rrf = someRandomIntern.makeForm("'make me coffee'", "Intern");
	if (rrf) {
		delete rrf;
	} else {
		std::cout << "Result: Intern safely returned NULL." << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;

	return 0;
}