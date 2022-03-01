NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)



ft_strlen.o : ft_strlen.c
	gcc -o prog -c ft_strlen.c


#clean :
	#rm -rf $(SRC)
#fclean : clean
	#rm -rf $(NAME)


