#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

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

void print_column_content(std::string content)
{
	int length;

	length = content.length();
	if (length < 11)
	{
		while (length - 10)
		{
			std::cout << " ";
			length++;
		}
		std::cout << content;
		
	}	
	else
		std::cout << content.substr(0, 9) << ".";
}

void	print_row(int index, Contact contact)
{
	std::cout << std::setw(10) << index;
	std::cout << "|";
	print_column_content(contact.getFirstName());
	std::cout << "|";
	print_column_content(contact.getLastName());
	std::cout << "|";
	print_column_content(contact.getNickname());
	std::cout << "|";
	print_column_content(contact.getPhone());
//	std::cout << "|";
/*	print_column_content(contact.getSecret());
	std::cout << "|" << std::endl;
*/
}

void print_table(PhoneBook pb)
{
	Contact *contact;
	int index = 1;
	while ((contact = pb.getContact(index)))
	{
		print_row(index, *contact);
		index++;
	}
	std::cout << std::endl;

}

void read_some()
{
	PhoneBook pb;
	std::string text;
	int index;
	std::string entry;
	std::cin >> text;
//	if (std::cin.eof())
//		return ;
	while (!std::cin.eof())
	{
//		if (std::cin.eof())
//			return ;
//		std::cout << text.length() << std::endl;
		if (text == "ADD")
		{
			collect_contact(&pb);
			std::cout << "adding contact" << std::endl;
		}
		if (text == "EXIT")
//		{
			return ;
//			std::cout << "exiting" << std::endl;
//		}
		if (text == "SEARCH")
		{
			
			//std::cout << "print contact table" << std::endl;
			print_table(pb);
			std::cout << "enter contact index" <<  std::endl;
//std::stoi
			std::cin >> entry;
			try
			{
				index = std::stoi(entry);
			}
			catch (...)
			{
				printf("problematic entry\n");
				continue;
			}
//			if (!std::cin)
//				break;
			if (!pb.getContact(index))
			{
				std::cout << "wrong contactt index provided" << std::endl;
				
				//break ;
				std::cin >> text;
				continue ;
			}
			else
			{
				std::cout << pb.getContact(index)->getFirstName() << std::endl;
				std::cout << pb.getContact(index)->getLastName() << std::endl;
				std::cout << pb.getContact(index)->getNickname() << std::endl;
				std::cout << pb.getContact(index)->getPhone() << std::endl;
				std::cout << pb.getContact(index)->getSecret() << std::endl;
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
