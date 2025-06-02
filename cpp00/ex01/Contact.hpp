#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

	private:
		std::string _first_name;   
		std::string _last_name;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
	public:
		std::string getFirstName()
		std::string getLastName()
		std::string getNickname()
		std::string getPhone()
		std::string getSecret()
		void setFirstName(std::string param)
		void setLastName(std::string param)
		void setNickname(std::string param)
		void setPhone(std::string param)
		void setSecret(std::string param)
}

#endif
