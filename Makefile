# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 14:07:38 by tjose             #+#    #+#              #
#    Updated: 2016/12/15 17:16:47 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
SRCFILES = main.c \
		   get_board.c \
		   get_pieces.c \
		   is_valid.c \
		   handle_pieces.c \
		   adjust_pieces.c
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))
LIBFT = ./libft/libft.a
LIBFTDIR = -I./libft
LIBFTL = -L./libft -lft
SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTL) -o $(NAME)

clean: 
	make -C ./libft clean
	rm -fr $(OBJDIR)
	
fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
