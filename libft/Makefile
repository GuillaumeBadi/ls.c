# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbatiot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 15:57:19 by vbatiot           #+#    #+#              #
#*   Updated: 2014/11/18 19:48:34 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC			= ft_atoi.c ft_isalpha.c\
			  ft_isalnum.c ft_isascii.c\
			  ft_strlen.c ft_tolower.c\
			  ft_toupper.c ft_isdigit.c\
			  ft_strcmp.c ft_strncmp.c\
			  ft_isprint.c ft_memset.c\
			  ft_putchar.c ft_putchar_fd.c\
			  ft_bzero.c ft_putstr.c\
			  ft_putstr_fd.c ft_strcpy.c\
			  ft_strncpy.c ft_strdup.c\
			  ft_strcat.c ft_strncat.c\
			  ft_strlcat.c ft_strstr.c\
			  ft_strnstr.c ft_strclr.c\
			  ft_putnbr.c ft_strchr.c\
			  ft_strrchr.c ft_putendl.c\
			  ft_putendl_fd.c ft_putnbr_fd.c\
			  ft_itoa.c ft_memchr.c\
			  ft_memcmp.c ft_memdel.c\
			  ft_strdel.c ft_memcpy.c\
			  ft_memccpy.c ft_memmove.c\
			  ft_memalloc.c ft_strnew.c\
			  ft_striter.c ft_strequ.c\
			  ft_strmap.c ft_strmapi.c\
			  ft_strsub.c ft_strtrim.c\
			  ft_strjoin.c ft_lstnew.c\
			  ft_lstdelone.c

SRCO = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $@ $(SRCO)

%.o: %.c
	gcc -c $(FLAGS) -I ./includes/ -o $@ $^

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
