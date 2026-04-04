#include "PmergeMe.hpp"

std::vector<int> &getJacobsthalSequence()
{
	static std::vector<int> sequence;
	return sequence;
}

void generateJacobsthalSequence(int max)
{
	std::vector<int> &sequence = getJacobsthalSequence();

	if (!sequence.size())
		sequence = {1, 3};
	while (sequence.back() < max) {
		int next = sequence.back() + 2 * sequence[sequence.size() - 2];
		sequence.push_back(next);
	}
}

