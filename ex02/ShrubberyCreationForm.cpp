#include "ShrubberyCreationForm.hpp"

// orthodox canonical form
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}
	// AFrom(_name, _target, _gradeToSign, _gradeToExecute)

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// member function
// 함수 이름 끝의 const는 이 함수가 속한 객체의 상태를 바꾸지 않겠다는 약속임.
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	// checkExecutable is in the AForm.
	this->checkExecutable(executor);

	std::string		filename = this->getTarget() + "_shrubbery";
	// ofstream 클래스의 outfile 객체 생성
	std::ofstream	outfile(filename.c_str()); // 쉘에서는 std::string을 인식하지 못하므로 문자열로 변환

	// 파일 열기 오류 처리.
	if (!outfile.is_open()) {
		throw std::runtime_error("Could not open file for writing");
	}
	// 파일에 쓰기
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