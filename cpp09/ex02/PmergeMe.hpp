#pragma once

#include <vector>
#include <deque>
//#include <pair>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>



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


template <typename Container>
void printContainerizedNumbers(Container &&numbers, size_t length)
{
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << numbers[i];
		if (i < length - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void fillContainer(int argc, char *argv[], Container &numbers)
{
	for (int i = 1; i < argc; i++)
		numbers.push_back(std::stoi(argv[i]));
}
/*
void debugPoint(int num)
{
	std::cout << "debug: " << num << std::endl;
}
*/
// 6 - 3
// 7 - 3
template <typename Container>
void pMergeInsertion(Container &numbers)
{
//	std::cout << "pmergeinsertion call" << std::endl;
	std::vector<std::pair<int, int>> pairs;
	Container 	bigs;
	Container	smalls;
	size_t		size = numbers.size();
	if (size < 2)
		return; 
	bool		hasStruggler = size % 2 ? true : false;
	int		struggler = numbers.back();
	for (size_t i = 0; i < size - 1; i += 2)
	{
		if (numbers.at(i) > numbers.at(i + 1))
			pairs.push_back({numbers.at(i), numbers.at(i + 1)});
		else
			pairs.push_back({numbers.at(i + 1), numbers.at(i)});
//		debugPoint(pairs.back().first);
		bigs.push_back(pairs.back().first);
	}
	pMergeInsertion(bigs);
	smalls.resize(bigs.size());
	for (std::pair<int, int> &pair : pairs)
	{
		auto iterInBigs = std::lower_bound(bigs.begin(), bigs.end(), pair.first);
		auto indexInSmalls = std::distance(bigs.begin(), iterInBigs);
		while (smalls.at(indexInSmalls))
			indexInSmalls++;
		smalls.at(indexInSmalls) = pair.second;
	}
//	smalls.push_back(pairs.back().second);
	if (hasStruggler)
		smalls.push_back(struggler);
	for (int num : smalls)
	{
		//size_t binSize = bigs.size();
		auto res = std::lower_bound(bigs.begin(), bigs.end(), num);
		if (res == bigs.end())
		{
			bigs.push_back(num);
		}
		else if (num)
		{
			//res = prev(res);
			bigs.insert(res, num);		
		}
	}
	
	/*
		split into pairs,
		find bigs parts of the pairs
		make a new container out of them,
		add numbers withou pairs into a container of smalls 
	*/
	// pMergeInsertion(bigs)
	/*
		assume that container of bigs is already sorted,
		start placing smalls ones into the bigs container using the binary search
	*/
	numbers = bigs;
}





/*
	for (int num : bigs)
	{
		for (std::pair<int, int> &p : pairs)
		{
			if (p.first == num)
			{
				smalls.push_back(p.second);
				p.first = -1;
				break;
			}
		}
	}
*/
