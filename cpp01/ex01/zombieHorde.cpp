#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	try {
		horde = new Zombie[N];
	}
	catch (...)
	{
		return (nullptr);
	}
	if (horde == nullptr)
		return (nullptr);
	for (int i = 0; i < N; i++)
	{
		try {
			
			horde[i] = Zombie(name);
//			horde[i].setName(&name);
		}
		catch (...)
		{
			delete[] horde;
			return (nullptr);
		}
	}
	return (horde);
}

