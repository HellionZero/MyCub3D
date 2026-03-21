# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 13:42:37 by lsarraci          #+#    #+#              #
#    Updated: 2026/03/21 20:10:57 by lsarraci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_converter.c \
		ft_printnbr.c \
		ft_printmod.c \
		ft_printhex.c \
		ft_printfloat.c \
		ft_printfloat_utils.c \
		ft_printptr.c \
		ft_printf_utils.c

OBJ = $(SRC:.c=.o)

RF = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RF) $(OBJ)

fclean: clean
	$(RF) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
	

