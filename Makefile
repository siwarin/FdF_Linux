# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 11:16:36 by mbraets           #+#    #+#              #
#    Updated: 2022/05/11 17:07:28 by siwarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC	= fdf
SRCS	= main.c drawer.c commands.c graphics.c reader.c
HEADER	= fdf.h
SRC_D	= srcs/
OBJ_D	= obj/
HEAD_D	= includes/
LIB	= Libft

INCLUDE = -Iincludes -Iminilibx -Ilibft
LBLIBS	= -Lminilibx -Llibft -L/usr/lib -lmlx -lXext -lX11 -lm
#	
#	Don't touch
#	
SRC			= $(addprefix $(SRC_D), $(SRCS))
HEADER_D	= $(addprefix $(HEAD_D), $(HEADER))
OBJ			= $(patsubst $(SRC_D)%.c, $(OBJ_D)%.o, $(SRC))
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -pedantic -g  $(INCLUDE)
LDFLAGS		= 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COLOR = \033
endif
ifeq ($(UNAME_S),Darwin)
	COLOR = \x1b
endif
ccred		= $(COLOR)[0;31m
ccgreen		= $(COLOR)[0;32m
ccyellow	= $(COLOR)[0;33m
ccblue		= $(COLOR)[0;34m
ccend		= $(COLOR)[0m


$(OBJ_D)%.o: $(SRC_D)%.c $(HEADER_D)
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(ccblue)Compiled "$<" successfully!$(ccend)\n"
$(EXEC): $(OBJ) $(HEADER_D)
	$(MAKE) -C Libft
	$(MAKE) -C minilibx
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS) Libft/libft.a
	@printf "$(ccgreen)Compiled "$@" successfully!$(ccend)\n"
all: $(EXEC)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(EXEC)
	$(MAKE) -C Libft fclean
	$(MAKE) -C minilibx clean
re: fclean all
.PHONY: clean fclean all
