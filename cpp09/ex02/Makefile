NAME = PmergeMe
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++20
SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: all
	./PmergeMe `shuf -i 1-30000000 -n 100000 | tr "\n" " "`
	./PmergeMe `shuf -i 1-30000000 -n 100000 | tr "\n" " "`

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean test fclean re
