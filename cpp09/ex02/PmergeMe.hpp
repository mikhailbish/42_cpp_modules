#pragma once

#include <vector>
//#include <pair>
#include <cmath>
#include <iostream>
#include <string>



// iter 1
// 12 34 22 11 17 19 15 14 23 32

// 12 34
// 11 22
// 17 19
// 14 15
// 23 32


// iter 2
// 34 22 19 15 32

// 22 34
// 15 19
// 32

// iter 3
// 19 34

// 15 19 22 32 34
// 14 17 11 23 12


void pmergeInsert(int argc, char *argv[])
{
	std::vector<int> holder;
	for (int i = 1; i < argc; i++)
		holder.push_back(std::stoi(argv[i]));
//		std::cout << std::stoi(argv[i]) << std::endl;
	for (size_t i = 0; i < holder.size(); i++)
		std::cout << holder.at(i) << std::endl;
	
//time start

//time stop
//time display
}
