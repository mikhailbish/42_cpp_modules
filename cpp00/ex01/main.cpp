#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <functional>

int prompt(char *arg, std::string &text, int flag)
{
	std::cout << arg << ": ";
	if (!std::getline(std::cin, text))
	{
		if (std::cin.eof())
		{
			throw std::runtime_error("asd");
			return 0;
		}
	}
	else if (!text.length())
	{
		throw std::invalid_argument("Empty string");
	}
	else if (flag == 1)
	{
		if (!(text == "ADD" || text == "SEARCH" || text == "EXIT"))
			throw std::invalid_argument("Wrong entry");
	}
//TODO: consider num validation here
	return (1);
}

int getContactDetail(char *promptText, std::string &storage)
{
	while (1)
	{
		try {
			if (!prompt(promptText, storage, 0))
				return 0;
			break ;
		}
		catch (std::invalid_argument &exception)
		{
			std::cout << "Invalid entry: " << exception.what() <<  std::endl;
		}
		catch (...)
		{
			throw std::runtime_error("assd");
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
	while (1)
	{
		try {
			if (!prompt(arg, text, true))
			{
				std::cout << "return after prompt" << std::endl;
				return ;
			}
		}
		catch (std::invalid_argument &err)
		{
			std::cout << "Usage:\nADD to start adding a new contact\nSEARCH to checkout entered contacts\nEXIT to close the program" << std::endl;
			continue ;
		}
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
			try
			{
				if (!prompt((char *)"Enter contact index", entry, false))
					return ;
				if (entry.length() != 1)
					throw 1;
				index = std::stoi(entry);
			}
			catch (std::invalid_argument &err)
			{
				continue ;
			}
			catch (...)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
				continue ;
			}
			contactFromBook = pb.getContact(index);
			if (!contactFromBook)
			{
				std::cout << "Wrong contact index provided!" << std::endl;
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
