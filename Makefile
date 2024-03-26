# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:09:26 by atok              #+#    #+#              #
#    Updated: 2022/11/07 13:46:58 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
RM		= rm -rf
AR		= ar rcs
INCLUDE	= ft_printf.h
CFLAGS	= -Wall -Wextra -Werror -I $(INCLUDE)

SRC		= ft_printf.c ft_putchar.c ft_putstr.c ft_pointer.c ft_number.c ft_unsigned.c ft_hex.c ft_percent.c
OBJS	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# name = .a archive file output name
# cc = compiler used
# rm = remove cmd + -rf remove evne the content inside
# ar = create archive .a file [man ar]
# 	r=library alreaxy existed replace old with new	
# 	c=create library if it did not exist
# 	s=apply index to eachfile/content and sort
# replce,create & sort
# cflags = to view all extra compiler warning/error message
# include = .h header file to link protoype
# src = .c files
# obj = .o compiled files
# .c.o = %.o : %.c (new for GNU)
# 		the cmd to compile .c to .o
# all = 'make' command
# clean = remove all .o
# fclean = remove all.o & .a
# re = re-make
# to use = 'make' to run program
# 		'make clean'
# 		'make fclean'
# 		'make re'
