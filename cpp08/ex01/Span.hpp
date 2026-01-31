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
		void addNumber(typename T::iterator begin, typename T::iterator end)
		{
			unsigned int sizeToAdd = end - begin;
// TODO: off by one?
			if (sizeToAdd + _storage.size() > N)
				return ;
			_storage.insert(_storage.end(), begin, end);
		}
		class InadequateAmountOfNumbersException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif
