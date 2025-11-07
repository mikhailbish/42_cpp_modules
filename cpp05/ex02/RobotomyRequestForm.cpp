#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "unset")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeSign(), other.getGradeExec(), other.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


void RobotomyRequestForm::_execute() const
{

	srand(time(0));
	
	std::cout << "brbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbr" << std::endl;
	int randomNum = rand();

	if (randomNum % 2)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
