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
