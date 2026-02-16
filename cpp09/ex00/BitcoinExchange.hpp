#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <sstream>

class BitcoinExchange : public std::map<std::string, float>
{
// TODO: OCF
/*
	struct bcePair {
		std::string date;
		float value;
	};
*/
	public:
		void	insertLine(std::string);
		void	match(std::string);
};

#endif
