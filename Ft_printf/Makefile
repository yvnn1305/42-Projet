NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@