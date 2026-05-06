NAME = libftprintf.a
SRC = ft_printf.c ft_printptr.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g2

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	-cc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: clean fclean re all

