#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "default_target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->checkExecutable(executor);

	std::string	filename = this->getTarget() + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	if (!outfile.is_open()) {
		throw std::runtime_error("Could not open file for writing");
	}
	outfile << "      _-_       " << std::endl;
	outfile << "   /~~    ~~\\   " << std::endl;
	outfile << " /~~        ~~\\" << std::endl;
	outfile << "{              }" << std::endl;
	outfile << " \\  _-    -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "       | |" << std::endl;
	outfile << "       | |" << std::endl;

	outfile.close();
}