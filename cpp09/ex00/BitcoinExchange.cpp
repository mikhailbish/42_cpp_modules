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
		//TODO: add validation for the end of stream
/*
		if (lineStream.peek() != lineStream.eof())
		{
		}
*/
		int iyear = stoi(year);
		int imonth = stoi(month);
		int iday = stoi(day);
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
		std::istringstream lineStream(line);
		std::string date;
		std::string value;
		float fvalue;
		getline(lineStream, date, '|');
		std::istringstream dateSpaceRem(date);
		getline(dateSpaceRem, date, ' ');
		getline(lineStream, value, '|');
		std::istringstream valSpaceRem(value);
		getline(valSpaceRem, value, ' ');
		getline(valSpaceRem, value, ' ');
		if (!isValidDate(date))
		{
			std::cout << "ERRORRRR date" << std::endl;
			return ;

		}
		fvalue = stof(value);
		if (fvalue < 0 || fvalue > 1000)
		{
			std::cout << "ERRORRRR value" << std::endl;
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
				std::cout << "ERRORRRR" << std::endl;
			}
		}
	}
	catch(std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}
