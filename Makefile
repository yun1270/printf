# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujung <yujung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 17:29:23 by yujung            #+#    #+#              #
#    Updated: 2021/04/24 17:25:14 by yujung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_printf_utils.c \
	print_char_str.c \
	print_num.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		ar rc $@ $^

$(OBJS) : $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : clean all

.PHONY : bonus all clean fclean re
