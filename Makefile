# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 10:00:24 by adube             #+#    #+#              #
#    Updated: 2023/07/24 16:40:58 by alexandrine      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	errors_mng.c init.c main.c mini_algo.c push_swap.c push.c reverse_rotate.c rotate.c swap.c utils.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Werror -Wextra

ARCHIVE = ar -rcs $(NAME) $(OBJ)

LIBERATE = rm -rf

LIBFT  = libft.a
LIBDIR = libft/

all: libft $(NAME)

$(NAME): $(OBJ)
	cp $(LIBDIR)$(LIBFT) $(NAME)
	$(ARCHIVE)
	@echo "\nPrintf Archived\n"

clean:
	$(LIBERATE) $(OBJ)
	$(LIBERATE) $(LIBDIR)*.o

fclean: clean
	$(LIBERATE) $(NAME)
	$(LIBERATE) $(LIBDIR)$(LIBFT)

re: fclean all

libft: 
	$(MAKE) -C $(LIBDIR)

.PHONY: all libft
