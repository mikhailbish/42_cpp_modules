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

#test: all
#	valgrind ./PmergeMe `shuf -i 1-30 -n 30 | tr "\n" " "` `shuf -i 1-30 -n 30 | tr "\n" " "` 
#	valgrind ./PmergeMe `shuf -i 1-31 -n 31 | tr "\n" " "` `shuf -i 1-31 -n 31 | tr "\n" " "` 

test: all
	./PmergeMe `shuf -i 1-30000000 -n 100000 | tr "\n" " "`
	./PmergeMe `shuf -i 1-30000000 -n 100000 | tr "\n" " "`

#test: all
#	./PmergeMe `shuf -i 1-30 -n 10 | tr "\n" " "`
#	./PmergeMe `shuf -i 1-30 -n 11 | tr "\n" " "`

#test: all
#	valgrind ./PmergeMe `shuf -i 1-30 -n 5 | tr "\n" " "`
#	valgrind ./PmergeMe `shuf -i 1-30 -n 6 | tr "\n" " "`

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean test fclean re
