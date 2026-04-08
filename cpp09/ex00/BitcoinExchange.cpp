#include "BitcoinExchange.hpp"

void BitcoinExchange::insertLine(std::string &line)
{
	std::istringstream lineStream(line);
	std::string date;
	std::string value;
	getline(lineStream, date, ',');
	getline(lineStream, value, ',');
	this->insert({date, stof(value)});
}

int getValidatedNumber(std::string &numStr)
{
	size_t endIndex;
	int number = stoi(numStr, &endIndex);
	if (numStr[endIndex] != 0)
		return -1;
	return number;
}

bool isEndOfIsStream(std::istringstream &someStream)
{
	return (someStream.peek() == std::char_traits<char>::eof());
}

bool isValidDate(std::string &date)
{
	try {
		std::istringstream lineStream(date);
		std::string year;
		std::string month;
		std::string day;
		getline(lineStream, year, '-');
		getline(lineStream, month, '-');
		getline(lineStream, day, '-');
		if (!isEndOfIsStream(lineStream))
			return false;
		int iyear = getValidatedNumber(year);
		if (iyear == -1)
			return false;
		int imonth = getValidatedNumber(month);
		if (imonth == -1)
			return false;
		int iday = getValidatedNumber(day);
		if (iday == -1)
			return false;
		auto dateValidator = std::chrono::year_month_day(std::chrono::year(iyear), std::chrono::month(imonth), std::chrono::day(iday));
		return dateValidator.ok();
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::validateHeader(std::string &line)
{
		std::string token;
		std::istringstream lineStream(line);
		lineStream >> token;
		if (token != "date")
			return (false);
		lineStream >> token;
		if (token != "|")
			return (false);
		lineStream >> token;
		if (token != "value")
			return (false);
		return (lineStream.peek() == std::char_traits<char>::eof());
}

void BitcoinExchange::match(std::string &line)
{
	try
	{
		size_t index;
		float fvalue;
		std::istringstream lineStream(line);
		std::string date;
		std::string value;
		std::string token;
		lineStream >> date;
		if (!date.size())
			throw 1;
		if (!isValidDate(date))
		{
			std::cout << "Error: invalid date: " << date << std::endl;
			return ;
		}
		lineStream >> token;
		if (token != "|")
		{
			std::cout << "Error: invalid separator: " << date << std::endl;
			return ;
		}
		lineStream >> value;
		if (!isEndOfIsStream(lineStream))
			throw 1;
		fvalue = stof(value, &index);
		if (fvalue < 0 || fvalue > 1000 || value[index])
		{
			std::cout << "Error: invalid value: " << value << std::endl;
			return ;
		}
		auto it = this->upper_bound(date);
		if (it == this->begin())
		{
			std::cout << "Error: input date " + date + " is before the first data entry" << std::endl;
			return;
		}
		if (!this->size())
		{
			std::cout << "No data has been provided" << std::endl;
			return;
		}
		--it;
		std::cout << date << " => " << value << " = " << it->second * fvalue << std::endl;
	}
	catch (...)
	{
		std::cout << "Error: invalid line: " << line << std::endl;
	}
}
