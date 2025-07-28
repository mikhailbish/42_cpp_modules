#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	try {
		horde = new Zombie[N];
	}
	catch (...)
	{
		return (0);
	}
	delete[] horde;
	return 0;
	if (!horde)
		return (0);
	for (int i = 0; i < N; i++)
	{
		try {
			horde[i].setName(&name);
		}
		catch (...)
		{
			delete[] horde;
			return (0);
		}
	}
	return (horde);
}

