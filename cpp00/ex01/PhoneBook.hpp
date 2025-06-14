#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int	_last_id_set;
		int	_num_set;

	public:
		PhoneBook();
		Contact	*getContact(int id);
		void	setContact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
};
#endif
