#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// Orthodox canonical form
		AForm();
		AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Getters
		std::string	getName() const;
		std::string	getTarget() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void			beSigned(const Bureaucrat& b);

		virtual void	execute(Bureaucrat const & executor) const = 0;

		void			checkExecutable(Bureaucrat const & executor) const;

		// Exception classes
		class GradeTooHighException: public std::exception {
			public: virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public: virtual const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
			public: virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
