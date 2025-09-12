#include "Zombie.hpp"
#define ZOMBIE_NUM 100

Zombie* zombieHorde( int N, std::string name );
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
