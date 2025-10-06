#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>
#include <iostream>

#define IDEA_COUNT 100

class Brain {
	private:
		std::string ideas[IDEA_COUNT];
	public:
		Brain();
		Brain(Brain &other);
		Brain &operator=(Brain &other) = default;
		~Brain();
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif
	
