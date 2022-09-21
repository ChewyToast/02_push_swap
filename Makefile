# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 09:32:53 by marvin            #+#    #+#              #
#    Updated: 2022/07/12 23:28:39 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	libft/ft_atoi.c			libft/ft_memmove.c		libft/ft_strlcpy.c	\
		libft/ft_bzero.c		libft/ft_memset.c		libft/ft_strlen.c	\
		libft/ft_calloc.c		libft/ft_putchar_fd.c	libft/ft_strmapi.c	\
		libft/ft_isalnum.c		libft/ft_putendl_fd.c	libft/ft_strncmp.c	\
		libft/ft_isalpha.c		libft/ft_putnbr_fd.c	libft/ft_strnstr.c	\
		libft/ft_isascii.c		libft/ft_putstr_fd.c	libft/ft_strrchr.c	\
		libft/ft_isdigit.c		libft/ft_split.c		libft/ft_strrspn.c	\
		libft/ft_isprint.c		libft/ft_strchr.c		libft/ft_strspn.c	\
		libft/ft_itoa.c			libft/ft_strdup.c		libft/ft_strtrim.c	\
		libft/ft_memchr.c		libft/ft_striteri.c		libft/ft_substr.c	\
		libft/ft_memcmp.c		libft/ft_strjoin.c		libft/ft_tolower.c	\
		libft/ft_memcpy.c		libft/ft_strlcat.c		libft/ft_toupper.c	\
		source/1ft_push_swap.c			source/2ft_check_input.c			\
		source/3stack_functions.c		source/4stack_operations.c			\
		source/5ft_shorter.c			source/6shorter_functions.c			\
		source/7short_cases.c

FLAGS =		-Werror -Wextra -Wall -o

CC = 		gcc

all:
			$(CC) $(FLAGS) $(NAME) $(SRC)

push_swap:
			$(CC) $(FLAGS) $(NAME) $(SRC)

clean:
			@rm -f	*.o

fclean:		clean
			@rm -f	$(NAME)

re:			fclean all

.PHONY: all clean fclean re
