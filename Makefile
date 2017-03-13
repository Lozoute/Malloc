##
## Makefile for malloc in /home/auzou_t/rendu/PSU_2014_malloc/thibaud
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Thu Jan 29 15:10:23 2015 Thibaud Auzou
## Last update Fri Feb 13 16:22:41 2015 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall
CFLAGS		+=
CFLAGS		+= -I./include/ -fPIC -shared

NAME		= libmy_malloc_$(HOSTTYPE).so

SRCS		= malloc.c \
		  wrappers.c \
		  show_alloc_mem.c \
		  calc_size.c \
		  free.c \
		  realloc.c \
		  calloc.c \
		  memalign.c \
		  free_list.c

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -fPIC -shared -o $(NAME) $(OBJS) -lpthread
		ln -sf $(NAME) libmy_malloc.so

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) libmy_malloc.so

re: fclean all

.PHONY: all clean fclean re
