# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hphanixa <hphanixa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:40:21 by hphanixa          #+#    #+#              #
#    Updated: 2022/01/12 10:48:34 by hphanixa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_strdup.c \
			  ft_atoi.c \
			  ft_itoa.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strtrim.c \
			  ft_putstr.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \

BONUS_SRCS	= ft_lstadd_front.c \
			  ft_lstadd_back.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstnew.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c \

INCS		= libft.h

OBJS		= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= libft.a
AR			= ar rcs

%.o			: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJS) $(INCS)
			$(AR) $(NAME) $(OBJS)

all			: $(NAME)

bonus		: $(OBJS) $(BONUS_OBJS) $(INCS)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
