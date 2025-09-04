#include <fstream>
#include <iostream>

int main(int argc, char *str[])
{
	if (argc != 4)
	//TODO: print error message
		return (1);
	size_t stringPosition = 0;
	
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
		//fileToRead.close();
		return (1);
	}	
	try 
	{
		while (getline(fileToRead, line))
		{
			textCollector += line;
			if (!fileToRead.eof())
				textCollector += "\n";
		}
		while (1)
		{
			stringPosition = textCollector.find(strToFind, 0);
			//std::cout << "str position" << stringPosition << std::endl;
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
		//fileToRead.close();
		//fileToWrite.close();
		return (1);
	}	
	//fileToRead.close();
	//fileToWrite.close();
	return (0);
}
