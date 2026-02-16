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
	std::istringstream lineStream(line);
	std::string date;
	std::string value;
// TODO: validate
	getline(lineStream, date, ',');
	getline(lineStream, value, ',');
	std::cout << date << " " << value << std::endl;
	//this->insert({date, stof(value)});
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
		std::istringstream lineStream(line);
		std::string date;
		std::string value;
		getline(lineStream, date, '|');
		std::istringstream dateSpaceRem(date);
		getline(dateSpaceRem, date, ' ');
		
		getline(lineStream, value, '|');
	//	std::istringstream valSpaceRem(value);
//		getline(valSpaceRem, value, ' ');
		std::cout << "DATE:"<< date << "!DATE END"<< std::endl << "VALUE:" << value << "!VALUE END" << std::endl;
	//	this->find(date) == this->end()
	}
	catch(std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}
