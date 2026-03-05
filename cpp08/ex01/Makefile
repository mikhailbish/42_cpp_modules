NAME = templates
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++11
EXTRAFLAGS= -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wnull-dereference
SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
