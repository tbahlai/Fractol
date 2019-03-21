#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 16:39:46 by tbahlai           #+#    #+#              #
#    Updated: 2019/02/13 16:39:47 by tbahlai          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    = fractol

SRC     = src/main.c \
			src/calc_fractals.c \
			src/draw_fractol.c \
			src/effect.c \
			src/menu.c \
			src/keys.c \
			src/initial_value.c \
			src/mouse.c \
			src/pthread.c

OBJ     = $(SRC:.c=.o)
LIBFT   = lib/
HDR  = includes/fractol.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: fractol"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> Fractol was deleted"


re:     fclean all

.PHONY:     re all clean fclean