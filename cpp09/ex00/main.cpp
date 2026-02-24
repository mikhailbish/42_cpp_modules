#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

void fileError()
{
	std::cout << "Error: could not open file." << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fileError();
		return 1;
	}
	try {
		BitcoinExchange bce;
		std::string line;
		std::ifstream dbFile("data.csv");
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
