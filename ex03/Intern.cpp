#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other) {}
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string formName, std::string target) {
	std::string	names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*f[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*f[i])(target);
		}
	}

	std::cout << "Error: Intern cannot create " << formName << " because it doesn't exists." << std::endl;
	return NULL;
}

AForm*	Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}
