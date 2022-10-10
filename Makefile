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

# ----------------------------- VAR DECLARATION ------------------------------ #

# Name value
NAME =			push_swap

# BONUS value
BNS =			checker

# Header for source
INCL = 			source/push_swap.h

# Bmlib libraries
BMLIB = 		bmlib/bmlib.a

# Bmlib header
BMLIB_INC =		bmlib/bmlib.h

# All source for the mandatory
SRC =			source/1ft_push_swap.c		source/3stack_functions.c	source/5ft_shorter.c		\
				source/7short_cases.c		source/2ft_check_input.c	source/4stack_operations.c	\
				source/6shorter_functions.c	source/8_short_cases_next.c

# All source for the bonus
BNS_SRC =		checker_source/checker.c	checker_source/checker_operations.c	\
				checker_source/utils.c		source/2ft_check_input.c			\
				source/3stack_functions.c	source/4stack_operations.c			\
				source/5ft_shorter.c		source/6shorter_functions.c			\
				source/7short_cases.c		source/8_short_cases_next.c

# All the mandatory objects
OBJ =			$(SRC:%.c=%.o)

# All the bonus objects
BNS_OBJ =		$(BNS_SRC:%.c=%.o)

# Git submodule update
GSU =			git submodule update

# Flags for GSU
GSU_FLAGS =		--remote --merge --recursive

# Flags to compile with gcc
FLAGS =			-Werror -Wextra -Wall

# Variable to compile .c files
CC = 			gcc

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
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;5;94m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
RANDM =			\033[38;5;95m
DARK_GREEN =	\033[38;5;64m
DARK_YELLOW =	\033[38;5;143m

# --------------------------------- ACTIONS ---------------------------------- #

# Main action of the makefile
all:
				@$(MAKE) $(NAME)

# Action to update the git submodules
update:
				@echo "$(YELLOW)Updating submodules"
				@$(GSU) $(GSU_FLAGS)

bonus:
				@$(MAKE) $(BNS)

bmlib:
				@$(MAKE) -C bmlib/

# Clean all the .o files
clean:
				@echo "$(DARK_YELLOW)Remove objects 🧹"
				@rm -f $(OBJ)
				@rm -f $(BNS_OBJ)

# Clean all the .o files and the push_swap or/and the checker
fclean:
				@$(MAKE) clean
ifeq "$(shell ls | grep push_swap)" "$(NAME)"
				@echo "$(DARK_YELLOW)Remove push_swap 🧼"
				@rm -f	$(NAME)
endif
ifeq "$(shell ls | grep checker)" "$(BNS) checker_source"
				@echo "$(DARK_YELLOW)Remove checker 🧼"
				@rm -f	$(BNS)
endif

# Clean all the .o files and the push_swap or/and the checker, and then restarts to the main action
re:
				@$(MAKE) fclean
				@$(MAKE) all

rebmlib:
				@$(MAKE) re -C bmlib/

%.o: %.c
				@echo "$(CYAN)compiling: [$(DARK_GRAY)$<$(CYAN)]"
				@$(CC) $(FLAGS) -c $< -o $@

$(NAME)::		$(BMLIB) $(OBJ)
				@echo "$(YELLOW)Linking...$(BROWN)"
				@$(CC) $(FLAGS) $(BMLIB) $(OBJ) -o $(NAME)

$(NAME)::
				@echo "$(DARK_GREEN)PUSH_SWAP COMPILED! ✅$(DEF_COLOR)"

$(BNS)::		$(BMLIB) $(BNS_OBJ)
				@echo "$(YELLOW)Linking...$(BROWN)"
				@$(CC) $(FLAGS) $(BMLIB) $(BNS_OBJ) -o $(BNS)

$(BNS)::
				@echo "$(DARK_GREEN)CHECKER COMPILED! ✅$(DEF_COLOR)"

$(BMLIB):
				@$(MAKE) -C bmlib/

.PHONY:		all update bonus bmlib clean fclean re rebmlib
