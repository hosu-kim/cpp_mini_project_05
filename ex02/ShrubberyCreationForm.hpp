#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream> // for file input/output

// 관목숲 생성
class ShrubberyCreationForm: public AForm {
	public:
		// orthodox canonical form
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};

#endif