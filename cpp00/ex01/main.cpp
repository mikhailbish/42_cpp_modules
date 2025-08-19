#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
/*
std::string &parsefield(string &prompt, )
{
	string field;

	std::getline(std::cin, field);
	if (field.length() == 0)
		return (nullptr)
	return (field);
}
*/
void prompt(char *arg, std::string &text)
{
	std::cout << arg << ": ";
	std::getline(std::cin, text);
}


void collect_contact(PhoneBook *pb)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	Contact *contactWip = pb->getNextContact();
//	int status = 1;
	while (1)
	{
		prompt((char *)"First Name", first_name);
		try {
			contactWip->setFirstName(first_name);
			break ;
		}
		catch (std::invalid_argument &exception)
		{
			std::cout <<"inv arg catch" << std::endl;
			throw ;
		}
		catch (...)
		{
		}
	}
//	status = 1;


	prompt((char *)"Last Name", last_name);
	contactWip->setLastName(last_name);

	prompt((char *)"Nickname", nickname);
	contactWip->setNickname(nickname);

	prompt((char *)"Phone", phone);
	contactWip->setPhone(phone);

	prompt((char *)"Secret", secret);
	contactWip->setSecret(secret);
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
	prompt(arg, text);
	while (!std::cin.eof())
	{
		if (text == "ADD")
		{
			collect_contact(&pb);
			std::cout << "adding contact" << std::endl;
		}
		if (text == "EXIT")
			return ;
		if (text == "SEARCH")
		{
			print_table(pb);
			std::cout << "enter contact index: ";
			std::getline(std::cin, entry);
			try
			{
				index = std::stoi(entry);
			}
			catch (...)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
				prompt(arg, text);
				continue;
			}
			contactFromBook = pb.getContact(index);
			if (!contactFromBook)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
				prompt(arg, text);
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
		prompt(arg, text);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	try {
		read_some(argv[0]);
	} catch (...)
	{

	}
	return (0);
}
