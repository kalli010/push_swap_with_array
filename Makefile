CC = cc
NAME = push_swap
NAME_B = checker
CFLAGS = -Wall -Wextra -Werror

source = push_swap.c util.c ft_strjoin.c ft_split.c ft_isdigit.c ft_atoi.c \
	 ft_strdup.c ft_strlen.c ft_memcpy.c



source_bonus =  




obj = $(source:.c=.o)
obj_bonus = $(source_bonus:.c=.o)
all:$(NAME)

$(NAME): $(obj) 
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

clean	:
	rm -fr $(obj) $(obj_bonus)
fclean	: clean
	rm -fr $(NAME) $(NAME_B)

re: fclean all

$(NAME_B):$(obj_bonus) 
	$(CC) $(CFLAGS) $(obj_bonus) -o $(NAME_B)
bonus: $(NAME_B)
