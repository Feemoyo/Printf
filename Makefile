# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 15:28:38 by fmoreira          #+#    #+#              #
#    Updated: 2021/09/06 13:47:58 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= rm -rf
NAME	= libftprintf.a

SRCS	= ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_strdup.c ft_memcpy.c ft_strlen.c ft_printf_utils.c \

OBJS	= $(SRCS:.c=.o)
PROGRAM	= main.out

all:		msg $(NAME)

msg:		
				@echo "Compiling..."

.c.o:		
				$(CC) $(CFLAGS) -c -fPIC $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				$(LIB1) $(NAME) $(OBJS)
				$(LIB2) $(NAME)

clean:		
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME) $(PROGRAM) *.a

compile:	fclean $(NAME)
				$(CC) -static main.c -L . -lftprintf $(CFLAGS) -lbsd -o $(PROGRAM)

so:			
				gcc -nostartfiles -shared -o ft_printf.so $(OBJS)

re:			fclean all

norme:		
				norminette ft_*.c ft_printf.h

.PHONY:		all clean fclean re compile .c.o $(NAME)
