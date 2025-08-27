#include "Contact.hpp"

std::string Contact::getFirstName()
{
	return (_first_name);
}
std::string Contact::getLastName()
{
	return (_last_name);
}
std::string Contact::getNickname()
{
	return (_nickname);
}
std::string Contact::getPhone()
{
	return (_phone);
}
std::string Contact::getSecret()
{
	return (_secret);
}

void Contact::setFirstName(std::string &param)
{
	_first_name = param;
}

void Contact::setLastName(std::string &param)
{
	_last_name = param;
}

void Contact::setNickname(std::string &param)
{
	_nickname = param;
}

void Contact::setPhone(std::string &param)
{
	_phone = param;
}

void Contact::setSecret(std::string &param)
{
	_secret = param;
}
