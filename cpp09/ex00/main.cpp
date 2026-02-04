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
		if (dbFile.fail() || inputFile.fail())
		{
			fileError();
			return (1);
		}
		while(getline(dbFile, line))
		{
			bce.insertLine(line);
			line = "";
		}
		while(getline(inputFile, line))
		{
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
