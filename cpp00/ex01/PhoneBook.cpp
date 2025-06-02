	public:
		PhoneBook()
		{
			_last_id_set = -1;
			_all_set = 0;
			_num_set = 0;
			// bzero contacts?
		}
		std::Contact	getContact(int id)
		{
			if (id >= _num_set)
				return (0) // ??? this?
			return (contacts[id]);
		}
		void	setContact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret)
		{
			int op_id;
			if (_last_id_set == -1 || _last_id_set > 6)
				op_id = 0;
			else
				op_id = _last_id_set + 1;
			contacts[op_id].setFirstName(first_name);
			contacts[op_id].setLastName(last_name);
			contacts[op_id].setNickname(nickname);
			contacts[op_id].setPhone(phone);
			contacts[op_id].setSecret(secret);
			_last_id_set = op_id;
		}
		
}
