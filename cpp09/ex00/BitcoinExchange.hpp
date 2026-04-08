#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <sstream>
# include <fstream>
# include <chrono>

# define DATA_FILE_NAME "data.csv"

struct BitcoinExchange : public std::map<std::string, float>
{
	public:
		static bool validateHeader(std::string &line);
		void	insertLine(std::string &);
		void	match(std::string &);
};

#endif
