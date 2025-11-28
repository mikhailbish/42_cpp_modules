#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"
# include <cstdint>

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer() = delete;
		Serializer(Serializer &) = delete;
		Serializer &operator=(Serializer &) = delete;
		~Serializer() = delete;
};

#endif
