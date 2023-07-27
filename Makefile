# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 10:00:24 by adube             #+#    #+#              #
#    Updated: 2023/07/27 11:16:24 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	errors_mng.c init.c main.c mini_algo.c push_swap.c push.c reverse_rotate.c rotate.c swap.c utils.c

NAME	=	push_swap

OBJS	=	${SRCS:.c=.o}


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g

RM		=	rm -rf

all:	${NAME} 
${NAME}:	${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}:	@${CC} ${CFLAGS}  ./libft/libft.a -o 

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} 

fclean:	clean
	@${RM} ${NAME}
	@${RM} 

re:	fclean all

.PHONY: all clean fclean re
