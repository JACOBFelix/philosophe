CC	=	gcc

RM	=	rm -f

NAME	=	philo

NAMESDL	=	philo_sdl

CFLAGS	+=	-Wall -Werror -Wextra -ansi -W -I ./includes -lpthread

DSRCS	=	./srcs/

SRCS	=	$(DSRCS)main.c \
		$(DSRCS)philosophe.c \
		$(DSRCS)handle.c \
		$(DSRCS)load.c \
		$(DSRCS)free.c

SRCSSDL	=	$(DSRCS)sdl_main.c \
		$(DSRCS)sdl_philosophe.c \
		$(DSRCS)sdl_handle.c \
		$(DSRCS)sdl_load.c \
		$(DSRCS)sdl_window.c \
		$(DSRCS)sdl_philosophe_gui.c \
		$(DSRCS)sdl_free.c

OBJS	=	$(SRCS:.c=.o)

OBJSSDL	=	$(SRCSSDL:.c=.o)

%.o: %.c
		@printf "[\033[0;32mCompiled\033[0m] % 35s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS)

all:		$(NAME)

sdl:		CFLAGS += -lSDLmain -lSDL -lSDL_image -lSDL_ttf -pedantic

sdl:		CFLAGS += -DBONUS_SDL

sdl:		$(NAMESDL)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
		@printf "[\033[0;34mAssembled\033[0m] % 34s\n" $(NAME)

$(NAMESDL):	$(OBJSSDL)
		@$(CC)  $(OBJSSDL) -o $(NAMESDL) $(CFLAGS)
		@printf "[\033[0;44mBonus Assembled\033[0m] % 28s\n" $(NAMESDL)

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mDeleted\033[0m] % 36s\n" $(OBJS)
		@$(RM) $(OBJSSDL)
		@printf "[\033[0;31mBonus Deleted\033[0m] % 30s\n" $(OBJSSDL)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAMESDL)
		@printf "[\033[0;35mRemoved\033[0m] % 36s\n" $(NAME)
		@printf "[\033[0;41mRemoved\033[0m] % 36s\n" $(NAMESDL)

re:		fclean all sdl

.PHONY:		all clean fclean re sdl Makefile
