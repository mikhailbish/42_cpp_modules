#ifndef SPAN_H
# define SPAN_H

# include <algorithm>

class Span {
	unsigned int N = 0;
	unsigned int _filled = 0;
	int	*_storage
	public:
		Span()
		Span(unsigned int);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
		void addNumber(int);
		unsigned int shortestSpan()
		unsigned int longestSpan();
}

#endif
