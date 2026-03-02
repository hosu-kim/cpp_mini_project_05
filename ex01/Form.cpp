#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

// Getters
std::string	AForm::getName() const { return _name; }
bool		AForm::getIsSigned() const { return _isSigned; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExecute() const { return _gradeToExecute; }

void		AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {
	os << "Form [" << f.getName() << "], signed: " << (f.getIsSigned() ? "Yes" : "No")
	   << ", sign grade: " << f.getGradeToSign()
	   << ", execute grade: " << f.getGradeToExecute();
	return os;
}