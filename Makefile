##
## Makefile for my_select in /home/sebastien/travaux/my_select
## 
## Made by sebastien
## Login   <sebastien@epitech.net>
## 
## Started on  Tue Jan 14 17:38:29 2014 sebastien
## Last update Fri Jan 17 11:23:23 2014 sebastien
##

SRC	= main.c \
	  list_linked.c \
	  utils.c \
	  mod_term.c \
	  print_list.c \
	  cmd.c \
	  disp_select.c \
	  move.c \
	  init_keys.c \
	  op.c \
	  init_others_keys.c \
	  list_func.c \
	  clear.c \
	  manage_cols.c \
	  signal.c \
	  my_puts.c

NAME	= my_select

CFLAGS	= -lncurses

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
