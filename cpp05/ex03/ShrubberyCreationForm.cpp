#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 135, "unset")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 135, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeSign(), other.getGradeExec(), other.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const std::string tree = 
R"(
     __ __                                     77
       V                              777    778877
                                    7778887777888887
                                  7788888888887788887
                                 7888888x88888887x887
                                 78888888x888888x887
                                  78888888x8888x887
                                   77788888x88x887
                                     7777888xx887
                                        7788X887
                                         77xXx7
                                           XXX
                                           XXX
                                          dXXXb
-----------------------------------------dXXXXX--------------
)";

void ShrubberyCreationForm::_execute() const
{
	std::ofstream fileToWrite(getTarget() + "_shrubbery");
	if (fileToWrite.fail())
		throw std::runtime_error("Cannot open file to write");
	fileToWrite << tree << std::endl;
}
