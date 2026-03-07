#include "RobotomyRequestForm.hpp"

// Robotomy: 사이보그화

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "defalt_target", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}
	// AFrom(_name, _target, _gradeToSign, _gradeToExecute)

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// member function
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkExecutable(executor);
	std::cout << "Vrrrzzzzzzzzzzzz!" << std::endl;

	// rand()는 무작위 정수를 생성하는 함수
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy failed for " << this->getTarget() << "." << std::endl;
	}
}