class Contact {
	private:
		std::string _first_name;   
		std::string _last_name;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
	public:
		std::string getFirstName()
		{
			return (_first_name);
		}
		std::string getLastName()
		{
			return (_last_name);
		}
		std::string getNickname()
		{
			return (_nickname);
		}
		std::string getPhone()
		{
			return (_phone);
		}
		std::string getSecret()
		{
			return (_secret);
		}
		void getFirstName(std::string param)
		{
			_first_name = param;
		}
		void getLastName(std::string param)
		{
			_last_name = param;
		}
		void getNickname(std::string param)
		{
			_nickname = param;
		}
		void getPhone(std::string param)
		{
			_phone = param;
		}
		void getSecret(std::string param)
		{
			_secret = param;
		}
		
};
