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

# -------------------------- DECLARATION --------------------------

NAME =		push_swap

INCL = 		source/push_swap.h

BMLIB = 	bmlib/bmlib.a

SRC =		$(shell ls source/*.c)

OBJ =		$(SRC:.c=.o)

FLAGS =		-Werror -Wextra -Wall

CC = 		gcc

# Colors
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m

# -------------------------- ACTIONS --------------------------

all:
		@echo "$(YELLOW) UPDATING GIT SUBMODULES... ⌛$(GREEN)"
		@git submodule update --init
		@git submodule update --remote --merge --recursive
		@echo "\n"
		@$(MAKE) $(NAME)

$(NAME): $(BMLIB) $(OBJ)
		@echo "$(YELLOW)\n\nLinking...$(GRAY)"
		@ar -rcs $(NAME) $(BMLIB)$(OBJ)
		@echo "$(GREEN)\n PUSH SWAP COMPILED! 🏁$(DEF_COLOR)\n"
		@echo "$(YELLOW)\t\t\t\t\t\t   ---------------------------\n"

$(BMLIB):
			$(MAKE) -C ../bmlib/

%.o: %.c 
	@echo "$(WHITE)\ncompiling $<"
	@echo "$(GRAY)"
	$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GRAY)--------------------------------------------------------------"

clean:
		@echo "$(RED)\n CLEANING ALL THE OBJECTS...🧹\n"
		@rm -f $(ALL_OBJ)

fclean:
		$(MAKE) clean
		@echo "\t$(GRAY)     AND"
		@echo "$(RED)\n     REMOVING PUSH_SWAP\n$(GRAY)"
		@rm -f	$(NAME)

re:		fclean all


.PHONY:		all clean fclean re
