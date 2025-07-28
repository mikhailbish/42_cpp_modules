#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie some = Zombie("test subject 1");
	some.announce();
	Zombie *other = newZombie("ww");
	other->announce();
	delete other;
	randomChump("random chump");
//	randomChum();
}
