##
## EPITECH PROJECT, 2017
## compile
## File description:
## my_printf
##

SRC_LIB	=	src/my_putchar.c	\
			src/my_put_nbr.c	\
			src/my_putstr.c	\
			src/my_putnbr_base.c	\
			src/my_string.c	\
			src/my_printf.c	\
			src/my_strlen.c	\
			src/my_strcpy.c	\

OBJ_LIB	=	$(SRC_LIB:.c=.o)

NAME	=	libmy.a

all:	 $(NAME)

$(NAME):	$(OBJ_LIB)
	ar rc $(NAME) $(OBJ_LIB)

clean:
	rm -f $(OBJ_LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all re clean fclean
