FLAG = -Wall -Werror -Wextra
NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isprint.c \
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putemdl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strcat.c ft_strcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strmstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \

OBJ = $(SRC:.c=.o)

B_SRC = ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c \
		ft_lstnew.c ft_lstsize.c

B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME) $(B_OBJ)
	ar rc $(NAME) $(B_OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) $< -o $@

clean:
	rm -rf $(OBJ)
	rm -f $(B_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re