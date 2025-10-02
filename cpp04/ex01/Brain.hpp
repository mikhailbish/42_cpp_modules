#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

#define IDEA_COUNT 100

class Brain {
	private:
		std::string ideas[IDEA_COUNT];
	public:
		Brain();
		Brain(Brain &other);
		Brain &operator=(Brain &other);
		~Brain();
};

#endif
	
