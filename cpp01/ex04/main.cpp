/*

Flow:
	open the file
	get text from file
	ifstream
	replace occurances of a str1 with str2
	write resulting text to a new file 
	fstream
	getline
*/
#include <fstream>
#include <iostream>

int main(int argc, char *str[])
{
	if (argc != 4)
	//TODO: print error message
		return (1);
	int flag = 1;
	size_t stringPosition = 0;
	std::string textCollector = "";
	std::string line;
	std::string textToWrite;
	std::ifstream fileToRead(str[1]);
	//fileToRead
	std::string buff;
//	fileToRead >> buff
	while (getline(fileToRead, line))
	{
		if (!flag)
			textCollector += "\n";
		if (flag)
			flag = 0;
		textCollector += line;
	}
	fileToRead.close();
	while (stringPosition < textCollector.length())
	{
		stringPosition = textCollector.find(, stringPosition)
//		if ()
//			flag = 1;
	}
	std::cout << textCollector << std::endl;
	return (0);
}
