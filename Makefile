# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:06:59 by jeongrol          #+#    #+#              #
#    Updated: 2023/02/20 19:53:35 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	mandatory/so_long.h

MLX_LINK = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS	=	mandatory/so_long.c \
			mandatory/so_long_ready.c \
			mandatory/so_long_read.c \
			mandatory/so_long_check.c \
			mandatory/so_long_screen.c \
			mandatory/so_long_event.c \
			mandatory/get_next_line.c \
			mandatory/get_next_line_utils.c

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	@make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I. $(MLX_LINK)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re