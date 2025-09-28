#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		bool _trySpendEnergy(void);

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& other) = default;
		ClapTrap& operator=(const ClapTrap &other) = default;
		~ClapTrap() = default;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getEnergy(void);
		unsigned int getAttackDamage(void);
		
};
