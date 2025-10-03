#include "Brain.hpp"

Brain::Brain()
{
	int i = 0;
	while(i < IDEA_COUNT)
	{
		if (i % 2)
			ideas[i] = "Bright";
		else
			ideas[i] = "Subpar";
		i++;
	}
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index >= IDEA_COUNT)
		return "";
	return ideas[index];
}

std::string Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= IDEA_COUNT)
		return "";
	return ideas[index] = idea;
}
