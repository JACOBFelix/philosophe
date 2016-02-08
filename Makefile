CC	=	gcc

RM	=	rm -f

NAME	=	philo

CFLAGS	+=	-Wall -Werror -Wextra -ansi -W -I ./includes -lpthread

DSRCS	=	./srcs/

SRCS	=	$(DSRCS)main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC)  $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
