#include "BitcoinExchange.hpp"

void fileError()
{
	std::cout << "Error: could not open file." << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc inputdata" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange bce;
		std::string line;
		std::ifstream dbFile(DATA_FILE_NAME);
		std::ifstream inputFile(argv[1]);
		bool start = true;
		if (dbFile.fail() || inputFile.fail())
		{
			fileError();
			return (1);
		}
		while (getline(dbFile, line))
		{
			if (start)
			{
				start = false;
				continue;
			}
			
			bce.insertLine(line);
			line = "";
		}
		start = true;
		while (getline(inputFile, line))
		{
			if (start)
			{
				if (!BitcoinExchange::validateHeader(line))
				{
					std::cout << "Invalid header in the input file" << std::endl;
					return (1);
				}
				start = false;
				continue;
			}
			bce.match(line);
			line = "";
		}
		
	}
	catch(std::exception &error)
	{
		std::cout << "Error: processing error." << std::endl;
	}
	return 0;
}
