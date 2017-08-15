NAME = libft.a

SRC =	ft_printf.c ft_quicksort.c put.c strings.c strings2.c conv.c mem.c\
		mem2.c array.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "minilibft compiled"

clean:
	@/bin/rm -f $(OBJ)
	@echo "objs ded"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f minilibft.h.gch
	@echo "lib ded"

re: fclean all
