# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:44:34 by tjose             #+#    #+#              #
#    Updated: 2016/12/12 14:24:36 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.o \
	   ft_putstr.o \
	   ft_putnbr.o \
	   ft_strcat.o \
	   ft_strncat.o \
	   ft_strlcat.o \
	   ft_strcmp.o \
	   ft_strncmp.o \
	   ft_strcpy.o \
	   ft_strncpy.o \
	   ft_strlen.o \
	   ft_strdup.o \
	   ft_strstr.o \
	   ft_strnstr.o \
	   ft_toupper.o \
	   ft_tolower.o \
	   ft_isalpha.o \
	   ft_isascii.o \
	   ft_isdigit.o \
	   ft_isprint.o \
	   ft_isalnum.o \
	   ft_is_wp.o \
	   ft_atoi.o \
	   ft_bzero.o \
	   ft_memcpy.o \
	   ft_memccpy.o \
	   ft_memchr.o \
	   ft_memcmp.o \
	   ft_memmove.o \
	   ft_memset.o \
	   ft_strchr.o \
	   ft_strrchr.o \
	   ft_itoa.o \
	   ft_memalloc.o \
	   ft_memdel.o \
	   ft_putchar_fd.o \
	   ft_putendl.o \
	   ft_putstr_fd.o \
	   ft_putendl_fd.o \
	   ft_putnbr_fd.o \
	   ft_strclr.o \
	   ft_strdel.o \
	   ft_strequ.o \
	   ft_striter.o \
	   ft_striteri.o \
	   ft_strjoin.o \
	   ft_strmap.o \
	   ft_strmapi.o \
	   ft_strnequ.o \
	   ft_strsplit.o \
	   ft_strsub.o \
	   ft_strtrim.o \
	   ft_strnew.o \
	   ft_lstnew.o \
	   ft_lstdelone.o \
	   ft_lstdel.o \
	   ft_lstadd.o \
	   ft_lstiter.o \
	   ft_lstmap.o \
	   ft_isneg.o \
	   ft_isprime.o \
	   ft_sqrt.o \
	   ft_pow.o

all: $(NAME)

$(NAME): $(SRCS)
	ar rc $(NAME) $(SRCS)

clean:
	/bin/rm -f $(SRCS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
