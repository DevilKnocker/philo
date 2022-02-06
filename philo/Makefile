CC = gcc
CFLAGS = -Werror -Wextra -Wall
INC = philo.h

SRCS = philo.c \
		philo_utils.c \
		philo_parsing.c \
		utils.c \
		utils2.c

SRCSB = checker_main.c \
		checker_utils.c \
		checker.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_memset.c \
		ft_split.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_substr.c \
		get_next_line.c \
		moves1.c \
		moves2.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSC:.c=.o)


NAME = philo

NAMEB = philo_bonus

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I $(INC). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ -I $(INC). $(OBJS)

$(NAMEB): $(OBJSB)
	$(CC) $(CFLAGS) -o $@ -I $(INC). $(OBJSB)

bonus: $(NAMEB)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY: all bonus clean fclean re checker