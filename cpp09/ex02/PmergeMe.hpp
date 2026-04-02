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

// 6 - 3
// 7 - 3
template <typename Container>
void pMergeInsertion(Container &numbers)
{
	std::vector<std::pair<int, int>> pairs;
	Container 	bigs;
	Container	smalls;
	size_t		size = numbers.size();
	bool		hasStruggler = size % 2 ? true : false;
	int		struggler = numbers.back();
	for (size_t i = 0; i < size; i += 2)
	{
		if (numbers[i] > numbers[i + 1])
			pairs.push_back({numbers[i], numbers[i + 1]})
		else
			pairs.push_back({numbers[i + 1], numbers[i]});
		bigs.push_back(pairs.back().first());
	}
	pMergeInsertion(bigs);
	// TODO: investigate optimization idea
	// move a bit
/*
	smalls.resize(bigs.size());
	int previosVal = -1;
	size_t repeatCounter = 0;

	for (std::pair<int, int> &p : pairs)
	{
		if (previosVal == pairs.first())
			repeatCounter++;
		else
			repeatCounter = 0;
		auto iterInBigs = std::lower_bound(bigs.begin(), bigs.end(), pairs.first());
		auto indexInSmalls = std::distance(bigs.begin(), positionInBigs) + repeatCounter;
		smalls.at(indexInSmalls) = *iterInBigs;
	}
*/
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
	smalls.push_back(pairs.back().second());
	if (hasStruggler)
		smalls.push_back(struggler);
	for 
	/*
		split into pairs,
		find bigs parts of the pairs
		make a new container out of them,
		add numbers withou pairs into a container of smalls 
	*/
	// pMergeInsertion(bigs)
	/*
		assume that container of bigs is already sorted,
		start placing smalls ones into the bigs container using the binary sort
	*/
	(void)numbers;
}
