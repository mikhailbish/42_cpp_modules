#ifndef SPAN_H
# define SPAN_H

# include <algorithm>
# include <vector>

class Span {
	unsigned int N = 0;
	std::vector<int> _storage;
	
	public:
		Span() = default;
		Span(unsigned int);
		Span(const Span &other);
		~Span() = default;
		Span &operator=(Span &other);
		void addNumber(int);
		template<typename T>
		void addNumber(T::iterator begin, T::iterator end)
		{
			unsigned int sizeToAdd = end - begin;
// TODO: off by one?
			if (sizeToAdd + _storage.size() > N)
				return ;
			_storage.insert(_storage.end(), begin, end);
		}
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif
