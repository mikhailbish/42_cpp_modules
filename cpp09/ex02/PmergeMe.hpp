#pragma once

#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <chrono>
#include <algorithm>

#define UNSET 0
std::vector<int> &getJacobsthalSequence();
void generateJacobsthalSequence(int max);

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

template <typename Container>
void pMergeInsertion(Container &numbers)
{
	std::vector<std::pair<int, int>> pairs;
	Container 	bigs;
	Container	smalls;
	size_t		size = numbers.size();
	if (size < 2)
		return; 
	for (size_t i = 0; i < size - 1; i += 2)
	{
		if (numbers.at(i) > numbers.at(i + 1))
			pairs.push_back({numbers.at(i), numbers.at(i + 1)});
		else
			pairs.push_back({numbers.at(i + 1), numbers.at(i)});
		bigs.push_back(pairs.back().first);
	}
	pMergeInsertion(bigs);
	smalls.resize(size / 2, UNSET);
	if (size % 2)
		smalls.push_back(numbers.at(size - 1));
	for (std::pair<int, int> &pair : pairs)
	{
		auto iterInBigs = std::lower_bound(bigs.begin(), bigs.end(), pair.first);
		auto indexInSmalls = std::distance(bigs.begin(), iterInBigs);
		while (smalls.at(indexInSmalls) != UNSET)
			indexInSmalls++;
		smalls.at(indexInSmalls) = pair.second;
	}
	size_t smallsSize  = smalls.size();
	size_t iSmalls = 0;
	int previousJacobsthalValue = 0;
	
	if (smallsSize)
	{
		bigs.insert(bigs.begin(), smalls[iSmalls]);
		previousJacobsthalValue = 1;
		++iSmalls;
	}
	std::vector<int> &jacobsthalSequence = getJacobsthalSequence();
	while (iSmalls < smallsSize)
	{
		int jacobsthalValue = std::min(static_cast<size_t>(jacobsthalSequence.at(iSmalls)), smallsSize);
		for (int currentlyAdding = jacobsthalValue; currentlyAdding > previousJacobsthalValue; --currentlyAdding)
		{
			int num = smalls.at(currentlyAdding - 1);
			auto insertTo = std::lower_bound(bigs.begin(), bigs.begin() + currentlyAdding + iSmalls + 1, num);
			bigs.insert(insertTo, num);
			++iSmalls;
		}
		previousJacobsthalValue = jacobsthalValue;
	}
/*
	for (int num : smalls)
	{
		auto res = std::lower_bound(bigs.begin(), bigs.end(), num);
		
// TODO: add std::is_sorted for verification
// TODO: is this relevant?
		if (res == bigs.end())
			bigs.push_back(num);
		else if (num)
			bigs.insert(res, num);		
	}
*/
	numbers = bigs;
}
