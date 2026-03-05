#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(NULL));

	Bureaucrat president("President", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat intern("Intern", 150);

	// 관목 생성
	std::cout << "\n--- [ TEST 1: Shrubbery Creation ] ---\n" << std::endl;
	{
		ShrubberyCreationForm shrub("home");
		intern.executeForm(shrub);
		manager.signForm(shrub);
		intern.executeForm(shrub);
		manager.executeForm(shrub);
	}

	std::cout << "\n--- [ TEST 2: Robotomy Request ] ---\n" << std::endl;
	{
		// Bender: 퓨처라마에 나오는 로봇 캐릭터
		RobotomyRequestForm robot("Bender");
		president.signForm(robot);
		president.executeForm(robot);
		president.executeForm(robot);
		president.executeForm(robot);
	}

	std::cout << "\n--- [ TEST 3: Presidential Pardon ] ---\n" << std::endl;
	{
		PresidentialPardonForm pardon("Poor Criminal");
		manager.signForm(pardon);
		president.signForm(pardon);
		president.executeForm(pardon);
	}

	std::cout << "\n--- [ TEST 4: Form Error Checking ] ---\n" << std::endl;
	try {
		AForm* f = new RobotomyRequestForm("Target");
		president.signForm(*f);
		president.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
