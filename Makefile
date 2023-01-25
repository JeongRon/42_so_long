NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f

all: $(NAME)

clean:
	make clean -C ./mlx
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: 
	make fclean
	make all

$(NAME):
	make -C ./mlx
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit practice3.c -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o$@

.PHONY: clean fclean re bonus all
