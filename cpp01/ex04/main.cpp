#include <fstream>
#include <iostream>

int main(int argc, char *str[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << str[0] << " <file to read> <string to replace> <string to replace with>" << std::endl;
		return (1);
	}
	size_t stringPosition = 0;
	try 
	{
		std::string fileName = str[1];
		std::string textCollector = "";
		std::string line;
		std::string textToWrite;
		std::string strToFind = str[2];
		std::string strToAdd = str[3];
		if (strToFind.length() == 0)
		{
			std::cout << "We do not look for empty strings" << std::endl;
			return (1);
		}
		std::ifstream fileToRead(fileName);
		if (fileToRead.fail())
		{
			std::cout << "Cannot open file to read" << std::endl;
			return (1);
		}
		std::ofstream fileToWrite(fileName + ".replace");
		if (fileToWrite.fail())
		{
			std::cout << "Cannot open file to write" << std::endl;
			return (1);
		}	
		while (getline(fileToRead, line))
		{
			textCollector += line;
			if (!fileToRead.eof())
				textCollector += "\n";
		}
		while (1)
		{
			stringPosition = textCollector.find(strToFind, 0);
			if (stringPosition == std::string::npos)
				break ; 
			textToWrite += textCollector.substr(0, stringPosition);
			textToWrite += strToAdd;
			textCollector = textCollector.substr(stringPosition + strToFind.length(), std::string::npos);
		}
		textToWrite += textCollector;
		fileToWrite << textToWrite;
	}
	catch (...)
	{
		std::cout << "Oups, something went wrong" << std::endl;
		return (1);
	}
	return (0);
}
