#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (std::string &entry : levels)
	{
		if (entry == level)
			break ;
		i++;	
	}
	switch (i)
	{
		case 0:
			std::cout << "[" << levels[0] << "]" << std::endl; 
			debug();
		case 1:
			std::cout << "[" << levels[1] << "]" << std::endl; 
			info();
		case 2:
			std::cout << "[" << levels[2] << "]" << std::endl; 
			warning();
		case 3:
			std::cout << "[" << levels[3] << "]" << std::endl; 
			error();
			break ;
		default:
			std::cout << "[" << "Bla bla bla" << "]" << std::endl; 
	}
}
