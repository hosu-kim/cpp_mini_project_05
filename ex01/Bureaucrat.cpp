#include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

// const 멤버 변수는 초기화 리스트에서만 초기화 가능
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade < 1)
	// throw가 실행되는 순간, 그 함수는 중단됩니다. 그리고 이 에러를 받아줄
	// catch 블록을 찾을 때까지 상위 함수로 거슬러 올라갑니다.
	// and exception class's constructor is executed.
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	// Self-assignment Guard
	// 
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const	std::string Bureaucrat::getName() const { return _name; }
int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

// newly added by the ex01
void	Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn't sign " << f.getName()
		          << " because " << e.what() << std::endl;
	}
}

// throw(): 예외 메시지를 가져오는 이 함수는 절대로 예외를 던지지 않겠다.
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
