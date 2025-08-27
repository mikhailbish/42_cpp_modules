#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <functional>

int prompt(char *arg, std::string &text)
{
	std::cout << arg << ": ";
	if (!std::getline(std::cin, text))
	{
		if (std::cin.eof())
		{
			std::cout << "ERRRRRRROR" << std::endl;
			return 0;
//			throw ;
		}
	}
	else if (!text.length())
		throw std::invalid_argument("Empty param");
	return (1);
}

int getContactDetail(char *promptText, std::string &storage)
{
	while (1)
	{
		try {
			if (!prompt(promptText, storage))
				return 0;
			break ;
		}
		catch (std::invalid_argument &exception)
		{
			std::cout <<"inv arg catch" << std::endl;
		}
		catch (...)
		{
			throw ;
		}
	}
	return (1);
}

int collect_contact(PhoneBook *pb)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	Contact *contactWip = pb->getNextContact();
	
	if (!getContactDetail((char *)"First Name", first_name))
		return (0);
	contactWip->setFirstName(first_name);

	if (!getContactDetail((char *)"Last Name", last_name))
		return (0);
	contactWip->setLastName(last_name);

	if (!getContactDetail((char *)"Nickame", nickname))
		return (0);
	contactWip->setNickname(nickname);

	if (!getContactDetail((char *)"Phone", phone))
		return (0);
	contactWip->setPhone(phone);

	if (!getContactDetail((char *)"Secret", secret))
		return (0);
	contactWip->setSecret(secret);
	return (1);
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
	std::cout << std::endl;
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
}

void read_some(char *arg)
{
	PhoneBook pb;
	Contact *contactFromBook;
	std::string text;
	std::string entry;
	int index;
	if (!prompt(arg, text))
		return;
	//while (!std::cin.eof())
	while (1)
	{
		if (text == "ADD")
		{
			if (!collect_contact(&pb))
				return ;
			std::cout << "adding contact" << std::endl;
		}
		if (text == "EXIT")
			return ;
		if (text == "SEARCH")
		{
			print_table(pb);
//			std::cout << "enter contact index: ";
//			std::getline(std::cin, entry);
			if (!prompt((char *)"Enter contact index:", entry))
				return ;
			try
			{
				index = std::stoi(entry);
			}
			catch (...)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
				if (!prompt(arg, text))
					return ;
				continue;
			}
			contactFromBook = pb.getContact(index);
			if (!contactFromBook)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
				if (!prompt(arg, text))
					return ;
				continue ;
			}
			else
			{
				std::cout << contactFromBook->getFirstName() << std::endl;
				std::cout << contactFromBook->getLastName() << std::endl;
				std::cout << contactFromBook->getNickname() << std::endl;
				std::cout << contactFromBook->getPhone() << std::endl;
				std::cout << contactFromBook->getSecret() << std::endl;
			}
		}
		if (!prompt(arg, text))
			return ;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	try {
		read_some(argv[0]);
	} catch (...)
	{
		std::cout << "caught some" << std::endl;
	}
	return (0);
}
