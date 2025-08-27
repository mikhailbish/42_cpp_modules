#include "PhoneBook.hpp"
PhoneBook::PhoneBook()
{
	_last_id_set = -1;
	_num_set = 0;
}

Contact	*PhoneBook::getContact(int id)
{
	if (id > _num_set)
		return (nullptr) ;
	if (id < 1)
		return (nullptr);
	return (&contacts[id - 1]);
}

Contact *PhoneBook::getNextContact()
{
	int op_id;
	if (_last_id_set == -1 || _last_id_set > 6)
		op_id = 0;
	else
		op_id = _last_id_set + 1;
	if (_num_set < 8)
		_num_set++;
	_last_id_set = op_id;
	return (&contacts[op_id]);
}
