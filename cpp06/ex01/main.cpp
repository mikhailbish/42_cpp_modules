#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data piece;
	uintptr_t raw = Serializer::serialize(&piece);
	Data *ptr = Serializer::deserialize(raw);
	if (ptr == &piece)
		return (0);
	return (1);
}
