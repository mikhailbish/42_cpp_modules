#include "BitcoinExchange.hpp"


/*
	FLOW:
	insert line
*/

/*
bcePair BitcoinExchange::_getKeyValue(std::string line, char delim)
{
	std::sstream lineStream(line);
	bcePair kv;
	return kv;
}*/

void BitcoinExchange::insertLine(std::string line)
{
//	bcePair kv = _getKeyValue(line );
	std::sstream lineStream(line);
	std::string date;
	std::string value;
// TODO: validate
	getline(lineStream, date, ',');
	getline(lineStream, value, ',');
	this.insert(date, stof(value));
}

void BitcoinExchange::match(std::string line)
{
// obtain key value
// validate key (date)
// use lowerbound / upperbound of map to figure own existing value
// validate value
// multiply, overflow checks?
// if no error - print line specific output
	try
	{
	}
	catch(std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}
