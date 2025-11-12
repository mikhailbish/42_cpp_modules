#include "Bureaucrat.hpp"


int main()
{
	try 
	{
		Bureaucrat asd("dude", 14);
		asd.promote();
		std::cout << asd << std::endl;
		asd.demote();
		std::cout << asd << std::endl;
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
