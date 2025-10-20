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
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(Brain &other)
{
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(Brain &other)
{
	std::cout << "Brain copy assginment" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index >= IDEA_COUNT)
		return "";
	return ideas[index];
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= IDEA_COUNT)
		return ;
	ideas[index] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
