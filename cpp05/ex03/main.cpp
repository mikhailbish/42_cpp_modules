#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern yo;
		AForm *form = yo.makeForm("RobotomyRequestForm", "wood");
		if (form == nullptr)
			return 1;
		yo.makeForm("obotomyRequestForm", "wood");
		Bureaucrat someone("fisrt", 1);
		someone.signForm(*form);
		someone.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
