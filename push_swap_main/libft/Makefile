# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 20:23:42 by alejarod          #+#    #+#              #
#    Updated: 2023/05/01 20:03:36 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_small.a

SRCS = ft_atoi.c ft_isdigit.c ft_isspace.c ft_long_atoi.c ft_putstr.c ft_split.c ft_strjoin_endspace.c \
ft_strlen.c ft_strdup.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs 

#---flag rules---

%.o: %.c
	$(CC) -c $(CFLAGS) $(SRCS)

#---subject---

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
