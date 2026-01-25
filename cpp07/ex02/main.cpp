#include "Array.hpp"

void setNextPrime(int &num);
#define ARR_LEN 100
int main()
{
	try {
		Array<int> intArr(ARR_LEN);
		Array<int> intArr2;
		iter<int>(intArr, ARR_LEN, &setNextPrime);
		iter<int>(intArr, ARR_LEN, &print<int>);
		intArr2 = intArr;
		iter<int>(intArr2, ARR_LEN, &print<int>);
		Array<int> intArr3 = intArr;
		iter<int>(intArr3, ARR_LEN, &print<int>);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}

bool isPrime(int num)
{
	int i = 2;
	if (num == 2)
		return true;
	while (num / i >= i)
	{
		if (num % i == 0)
			return (false);
		i++;
	}
	return (true);
	
}

int getNextPrime()
{
	static int num = 1;
	num++;
	while (!isPrime(num))
	{
		num++;
	}
	return (num);
}

void setNextPrime(int &num)
{
	num = getNextPrime();
}
