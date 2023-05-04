# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:01:34 by alejarod          #+#    #+#              #
#    Updated: 2023/05/04 22:32:58 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# hide terminal output
#.SILENT:

# Variables
NAME = push_swap
CC = gcc -g3 -fsanitize=address
CFLAGS	= -Wall -Werror -Wextra
RM = rm
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN_PRE = '\033[32m'
RED_PRE = '\033[31m'
RESET_BLACK = '\033[0m'

# External Paths and libraries
LIBFT_PATH = ./libft
LIBFT_A = $(LIBFT_PATH)/libft_small.a

# Project sources and objects
SRCS_PATH = ./srcs
SRCS = ft_check_argv.c ft_cost.c ft_list.c ft_movements.c ft_position.c ft_push.c ft_reverse_rotate.c \
ft_rotate.c ft_save_numbers.c ft_sort_large.c ft_sort_three.c ft_swap.c ft_utils.c main.c
HEADER = $(SRCS_PATH)/push_swap.h

OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

#Object rule and move them to the object folder
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@


# Targets
all: $(NAME)

$(NAME): $(OBJS)
	MAKE -C $(LIBFT_PATH)
	@echo $(GREEN_PRE)"LIBFT_SMALL COMPILED !"$(RESET_BLACK)
	$(CC) $^ $(LIBFT_A) -o $@
	@echo $(GREEN_PRE)"PUSH_SWAP COMPILED !"$(RESET_BLACK)
	@echo "./push_swap <ARGS> to run"

#create the object directory
$(OBJS_PATH):
	mkdir $@

#test
#./push_swap 6 3 4 67 34 12 | ./checker_mac 6 3 4 67 34 12
NUMS = 500
ARG = -990 925 -442 916 448 783 -876 -827 80 -935 -493 413 -553 861 -253 105 -43 736 -563 -361 -572 906 374 -720 -115 997 -426 -665 -848 -381 -154 172 -685 -831 -880 -519 -141 667 432 -236 738 866 534 607 -457 296 697 418 884 629 655 167 -509 -119 832 -266 505 773 -814 751 873 326 524 -371 290 12 924 509 914 -478 -660 -944 -958 -706 22 -693 199 -410 190 682 902 -274 -259 460 523 510 439 518 -235 -622 533 836 -349 -208 -797 -809 -355 -569 88 -634
test: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG)

#test and count
checker_linux: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker_mac: $(NAME)
#	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

# removes the .o files
clean:
	@$(RM) -rf $(OBJS_PATH)
	MAKE -C $(LIBFT_PATH) clean
	@echo $(RED_PRE)"OBJECT FILES DELETED !"$(RESET_BLACK)

# removes .o files & push_swap executable
fclean: clean
	@$(RM) $(NAME)
	MAKE -C $(LIBFT_PATH) fclean
	@echo $(RED_PRE)"PUSH_SWAP EXEC DELETED !"$(RESET_BLACK)

re: fclean all

normi:
	norminette $(SRCS_PATH)/*.c $(HEADER) 

.PHONY: all test checker clean fclean re normi