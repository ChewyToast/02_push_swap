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

PUSW =		push_swap

CHKR =		checker

INCL = 		source/push_swap.h

BMLIB = 	bmlib/bmlib.a

SRC =		$(shell ls source/*.c)

CHK_SRC =	$(shell ls checker_source/*.c) $(shell ls source/*.c | grep -v 1ft_push_swap.c)

OBJ =		$(SRC:.c=.o)

CHK_OBJ =	$(CHK_SRC:.c=.o) 

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
		@$(MAKE) $(PUSW)

$(PUSW):: $(BMLIB) $(OBJ)
		@echo "$(YELLOW)\n\nLinking...$(GRAY)"
		@$(CC) $(FLAGS) $(BMLIB) $(OBJ) -o $(PUSW)
		@echo "$(GREEN)\n🏁 PUSH SWAP COMPILED! 🏁$(DEF_COLOR)"

$(PUSW)::
		@echo "$(GREEN)DONE"

$(CHKR): $(BMLIB) $(CHK_OBJ)
		@echo "$(YELLOW)\n\nLinking...$(GRAY)"
		@$(CC) $(FLAGS) $(BMLIB) $(CHK_OBJ) -o $(CHKR)
		@echo "$(MAGENTA)\n🏁 CHECKER COMPILED! 🏁$(DEF_COLOR)"

$(BMLIB):
		@$(MAKE) all -C bmlib/
		@$(MAKE) clean -C bmlib/

%.o: %.c 
		@echo "$(WHITE)ncompiling $< $(GRAY)"
		$(CC) $(FLAGS) -c $< -o $@
		@echo "$(GRAY)--------------------------------------------------------------"

ps:
		@$(MAKE) $(PUSW)

bonus:
		@$(MAKE) $(CHKR)

bmclean:
		@$(MAKE) clean -C bmlib/

bmfclean:
		@$(MAKE) fclean -C bmlib/

clean:
		@echo "$(MAGENTA)CLEANING ALL THE OBJECTS...🧹"
		@rm -f $(OBJ)

fclean:
		@$(MAKE) clean
		@echo "$(GRAY)&&"
		@echo "$(RED)REMOVING PUSH_SWAP❌$(GRAY)"
		@rm -f	$(PUSW)

cleanbns:
		@echo "$(MAGENTA)CLEANING ALL THE CHECKER OBJECTS...🧹"
		@rm -f $(CHK_OBJ)
		@rm -f $(OBJ)

fcleanbns:
		@$(MAKE) cleanbns
		@echo "$(GRAY)&&"
		@echo "$(RED)REMOVING CHECKER❌$(GRAY)"
		@rm -f	$(CHKR)

cleanall:
		@$(MAKE) bmclean
		@$(MAKE) clean

fcleanall:
		@$(MAKE) bmfclean
		@$(MAKE) fcleanbns
		@$(MAKE) fclean

re:		fclean all

reps:
		@$(MAKE) fclean
		@$(MAKE) ps

rebns:
		@$(MAKE) fcleanbns
		@$(MAKE) bonus
reall:
		@$(MAKE) re -C bmlib/
		@$(MAKE) re


.PHONY:		all clean fclean re ps bmclean bmfclean cleanall fcleanall
