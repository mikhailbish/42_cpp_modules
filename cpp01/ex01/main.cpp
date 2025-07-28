#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );
#define ZOMBIE_NUM 100
int main()
{
	Zombie some = Zombie("test subject 1");
	some.announce();

	Zombie *wow = zombieHorde(ZOMBIE_NUM, "Vasya");
	if (!wow)
		return (1);
	for (int i = 0; i < ZOMBIE_NUM; i++)
		wow[i].announce();
	delete[] wow;
//	Zombie *other = newZombie("ww");
//	other->announce();
//	delete other;
//	randomChump("random chump");
//	randomChum();
}
