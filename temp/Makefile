# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwarin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 19:54:43 by siwarin           #+#    #+#              #
#    Updated: 2022/05/11 16:41:36 by siwarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS= -Wall -Wextra -Werror

CC = gcc

HEADER = includes/FdF.h

LIBFT = Libft

LIB = Libft/libft.a

INCL = /usr/local/include

SRCS = srcs/main.c srcs/commands.c srcs/drawer.c srcs/graphics.c srcs/reader.c Libft/libft.a

OBJS = $(SRCS:.c=.o)

FRAM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -o $@ -I $(INCL) -Iminilibx $(SRCS) $(LIB) -Lminilibx -L /usr/lib -lXext -lX11 -lm 

$(LIB) : force
	@make -C Libft/

force :
	@true
	
clean :
	rm -f $(OBJS)
	@(cd $(LIBFT) && $(MAKE) $@)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
