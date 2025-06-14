NAME = book
CC = c++
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRCS = PhoneBook.cpp \
	Contact.cpp \
	main.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
