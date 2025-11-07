#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form testFormA("form1", 4, 4); 
	Form testFormB("form2", 4, 4); 
	testFormB = testFormA;
	Form testFormC(testFormB);
	std::cout << testFormC << std::endl;
	try 
	{
		Bureaucrat asd("dude", 14);
		asd.promote();
		std::cout << asd << std::endl;
		asd.demote();
		std::cout << asd << std::endl;
		asd.signForm(testFormA);
	}
	catch (std::exception &e)
	{	
		std::cout << e.what()<< std::endl;
	}

	try 
	{
		Bureaucrat asd("dude", 1);
		asd.promote();
		std::cout << asd << std::endl;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what()<< std::endl;
	}
	try 
	{
		Bureaucrat asd("dude", 150);
		asd.demote();
		std::cout << asd << std::endl;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what()<< std::endl;
	}
	
	return (0);
}
