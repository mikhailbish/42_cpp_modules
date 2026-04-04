NAME = PmergeMe
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++20 -g
SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: all
	valgrind ./PmergeMe `shuf -i 1-100000 -n 30 | tr "\n" " "`

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean test fclean re
