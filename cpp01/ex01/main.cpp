#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );
#define ZOMBIE_NUM 100
int main()
{
	Zombie *wow = zombieHorde(ZOMBIE_NUM, "Vasya");
	if (wow == nullptr)
		return (1);
	for (int i = 0; i < ZOMBIE_NUM; i++)
		wow[i].announce();
	delete[] wow;
	return (0);
}
