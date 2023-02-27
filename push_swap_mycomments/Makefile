# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:01:34 by alejarod          #+#    #+#              #
#    Updated: 2023/02/22 18:20:09 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# hide terminal output
.SILENT:

# Variables
NAME = push_swap
CC = gcc
CFLAGS	= -Wall -Werror -Wextra -g3 #-fsanitize=address
RM = rm -rf
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN_PRE = '\033[32m'
RED_PRE = '\033[31m'
RESET_BLACK = '\033[0m'

# Paths
LIBFT_PATH = libft
SRCS_PATH = srcs

# Files
LIBFT_SRCS = $(wildcard $(LIBFT_PATH)/*.c *.h)
SRCS = $(wildcard $(SRCS_PATH)/*.c)
OBJS = $(LIBFT_SRCS:.c=.o) $(SRCS:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN_PRE)"PUSH_SWAP COMPILED !"$(RESET_BLACK)
	@echo "./push_swap <ARGS> to run"

# rule to compile .c into .o
# $< refers to %.o and $@ refers to %.c
%.o: %.c %.h
	@$(CC) $(CFLAGS) -c $< -o $@

#test and count
checker_linux: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker_mac: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(NUMS)))
	./push_swap $(ARG) | ./checker_mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

# removes the .o files
clean:
	@$(RM) $(OBJS)
	@echo $(RED_PRE)"OBJECT FILES DELETED !"$(RESET_BLACK)

# removes .o files & push_swap executable
fclean: clean
	@$(RM) $(NAME)
	@echo $(RED_PRE)"PUSH_SWAP EXEC DELETED !"$(RESET_BLACK)

re: fclean all

.PHONY: all clean fclean re