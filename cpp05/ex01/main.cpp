#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form testFormB("form2", 4, 4); 
	Form testFormC(testFormB);
	std::cout << testFormC << std::endl;
	try 
	{
		Form testFormK("formK", 0, 20); 
		std::cout << testFormK << std::endl;
		
		Form testFormA("form1", 20, 20); 
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
		Form testFormA("form1", 1, 1); 
		Bureaucrat asd("dude", 2);
		asd.demote();
		asd.signForm(testFormA);
		std::cout << asd << std::endl;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what()<< std::endl;
	}
	try 
	{
		Bureaucrat asd;
		Form form;
		asd.signForm(form);
		std::cout << asd << std::endl;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what()<< std::endl;
	}
	
	return (0);
}
