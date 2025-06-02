
class PhoneBook {
	private:
		Contact::Contact contacts[8];
		int	_last_id_set;
		int	_num_set;
	public:
		PhoneBook();
		Contact::Contact	getContact(int id);
//		void	setContact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
		void	setContact(Contact::Contact contact);
}
