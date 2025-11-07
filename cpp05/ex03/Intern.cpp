#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *ptr = nullptr;
	std::string message = "Intern could not find a form";
	try {
		if (name == "ShrubberyCreationForm")
			ptr = (new ShrubberyCreationForm(target));
		if (name == "RobotomyRequestForm")
			ptr = (new RobotomyRequestForm(target));
		if (name == "PresidentialPardonForm")
			ptr = (new PresidentialPardonForm(target));
		if (!(ptr == nullptr))
			message = "Intern creates " + name;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << message << std::endl;
	return ptr;
}
