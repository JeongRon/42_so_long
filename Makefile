NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalnum.c ft_isdigit.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_B = 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f

ifdef BONUS
	OBJS_M = $(OBJS_B)
else
	OBJS_M = $(OBJS)
endif

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: 
	make fclean
	make all

bonus : $(OBJS_B)
	make BONUS=1

$(NAME): $(OBJS_M)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean fclean re bonus all
