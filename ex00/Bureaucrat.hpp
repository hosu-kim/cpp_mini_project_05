#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
	// Orthodox canonical form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		const	std::string getName() const;
		int					getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception {
			public:
				// 자식에서 부모의 함수를 재정의했을 때 자식이 수정한 버전이 실행되게 한다.
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif