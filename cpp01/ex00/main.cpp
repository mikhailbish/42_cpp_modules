#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie some = Zombie("test subject 1");
	some.announce();
	Zombie *other = newZombie("ww");
	if (other == NULL)
		return 1;
	other->announce();
	delete other;
	randomChump("random chump");
}
