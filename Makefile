NAME = pipex

SRCS =	fork.c \
		error.c \
		main.c \
		check_cmd.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined

CC = clang

RM = rm -rf

INCLUDES += -Ilibft/

all : $(NAME)

%.o		: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES) 

$(NAME) : $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) -lft -Llibft

clean :
	make clean -C libft/
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft/

re : fclean all

.PHONY: re clean fclean all
