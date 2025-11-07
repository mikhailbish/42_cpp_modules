#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
	        ShrubberyCreationForm asd;
		Bureaucrat clerk("Vova", 150);
		Bureaucrat robotest("diff", 30);
		robotest.signForm(asd);
		RobotomyRequestForm wasd("special");
		robotest.signForm(wasd);
		robotest.executeForm(wasd);
		clerk.executeForm(asd);
		PresidentialPardonForm preFrom("wow");
		Bureaucrat someone("fisrt", 1);
		someone.signForm(preFrom);
		someone.executeForm(preFrom);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
