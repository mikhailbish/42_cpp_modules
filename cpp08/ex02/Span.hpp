#ifndef SPAN_H
# define SPAN_H

# include <algorithm>
# include <set>

class Span {
	unsigned int N = 0;
	std::multiset<int> _storage;
	
	unsigned int _getDistance(int, int) const;	
	public:
		Span() = default;
		Span(unsigned int);
		Span(const Span &other);
		~Span() = default;
		Span &operator=(Span &other);
		void addNumber(int);
		template<typename T>
		void addNumber(T begin, T end)
		{
			unsigned int sizeToAdd = std::distance(begin, end);
// TODO: off by one?
			if (sizeToAdd + _storage.size() > N)
				return ;
			_storage.insert(begin, end);
		}
		class InadequateAmountOfNumbersException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif
