# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalee <yalee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 16:07:08 by yalee             #+#    #+#              #
#    Updated: 2022/08/15 23:49:58 by yalee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_print_hex.c ft_print_pointer.c ft_print_string.c ft_itoa.c\
	ft_print_unsigned.c libftprintf.c ft_print_else.c ft_putchar_fd.c

CCOBJ = gcc -Wall -Wextra -Werror -c

LIBFT = -L./libft -lft

OBJS = $(SRC:.c=.o)

CCLIB = ar rcs $(NAME)

MAKE = make

all: $(NAME)

$(NAME):
	$(CCOBJ) $(SRC)
	$(CCLIB) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all