#include "BitcoinExchange.hpp"

void BitcoinExchange::insertLine(std::string line)
{
	std::istringstream lineStream(line);
	std::string date;
	std::string value;
	getline(lineStream, date, ',');
	getline(lineStream, value, ',');
	this->insert({date, stof(value)});
}

int getValidatedNumber(std::string numStr)
{
	size_t endIndex;
	int number = stoi(numStr, &endIndex);
	if (numStr[endIndex] != 0)
		return -1;
	return number;
}

bool isEndOfIsStream(std::istringstream &someStream)
{
	if (someStream.peek() == std::char_traits<char>::eof())
		return true;
	return false;
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

void BitcoinExchange::match(std::string line)
{
	try
	{
		size_t index;
		size_t size;
		std::istringstream lineStream(line);
		std::string date;
		std::string value;
		float fvalue;
		getline(lineStream, date, '|');
		std::istringstream dateSpaceRem(date);
		size = date.size();
		getline(dateSpaceRem, date, ' ');
		if (size == date.size())
			throw 1;
		getline(lineStream, value, '|');
		size = value.size();
		std::istringstream valSpaceRem(value);
		getline(valSpaceRem, value, ' ');
		getline(valSpaceRem, value, ' ');
		if (size == value.size())
			throw 1;
		if (!isEndOfIsStream(lineStream))
			throw 1;
		if (!isEndOfIsStream(dateSpaceRem))
			throw 1;
		if (!isEndOfIsStream(valSpaceRem))
			throw 1;
		if (!isValidDate(date))
		{
			std::cout << "Error: invalid date: " << date << std::endl;
			return ;

		}
		fvalue = stof(value, &index);
		if (fvalue < 0 || fvalue > 1000 || value[index])
		{
			std::cout << "Error: invalid value: " << value << std::endl;
			return ;
			
		}
		float result;
		auto it = this->find(date);
		if (it != this->end())
		{
				result = it->second * fvalue;
				std::cout << date << " => " << value << " = " << result << std::endl;
		}
		else
		{
			it = this->lower_bound(date);
			if ((it != this->end() && it != this->begin()) || (it == this->end() && this->size()))
			{
				--it;
				result = it->second * fvalue;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
			else
			{
				std::cout << "Error: date before the first entry" << std::endl;
			}
		}
	}
	catch(...)
	{
		std::cout << "Error: invalid line: " << line << std::endl;
	}
}
