#include "AForm.hpp"

AForm::AForm()
	: _name("default"), _target("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute)
	: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

// Getters
std::string	AForm::getName() const { return _name; }
std::string	AForm::getTarget() const { return _target; }
bool		AForm::getIsSigned() const { return _isSigned; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExecute() const { return _gradeToExecute; }

void		AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecutable(Bureaucrat const & executor) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}
const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}
const char*	AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {
	os << "Form: " << f.getName() << ", Target: " << f.getTarget()
	   << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << f.getGradeToSign()
	   << ", Execute Grade: " << f.getGradeToExecute();
	return os;
}