#include "PhoneBook.hpp"
#include <string>
#include <iostream>


void collect_contact(PhoneBook *pb)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	
	std::cout << "First Name: "; //<< std::endl;
	std::cin >> first_name;
	std::cout << "Last Name: "; //<< std::endl;
	std::cin >> last_name;
	std::cout << "Nickname: "; //<< std::endl;
	std::cin >> nickname;
	std::cout << "Phone: "; //<< std::endl;
	std::cin >> phone;
	std::cout << "Secret: "; //<< std::endl;
	std::cin >> secret;
	pb->setContact(first_name, last_name, nickname, phone, secret);
	
}

void read_some()
{
	PhoneBook pb;
	std::string text;
	int index;
	std::cin >> text;
//	if (std::cin.eof())
//		return ;
	while (!std::cin.eof())
	{
//		if (std::cin.eof())
//			return ;
		std::cout << text.length() << std::endl;
		if (text == "ADD")
		{
			collect_contact(&pb);
		}
			std::cout << "adding contact" << std::endl;
		if (text == "EXIT")
			std::cout << "exiting" << std::endl;
		if (text == "SEARCH")
		{
			
			std::cout << "print contact table" << std::endl;
			std::cout << "enter contact index";
			std::cin >> index;
			if (!pb.getContact(index))
			{
				std::cout << "wrong contactt index provided" << std::endl;
				break ;
				std::cin >> text;
			}
		}
		std::cin >> text;
	}
}

int main()
{
	read_some();
	return (0);
}
