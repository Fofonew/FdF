# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <doriol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 04:00:07 by doriol            #+#    #+#              #
#    Updated: 2017/05/10 20:24:11 by doriol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ./srcs/parsing.c\
	   ./srcs/action.c\
	   ./srcs/make_window.c\
	   ./srcs/check_error.c\

SRCS2 = parsing.o\
		action.o\
		make_window.o\
		check_error.o\

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -Wall -Wextra -Werror -I libft/includes/ -c $(SRCS)
	@gcc -o $(NAME) $(SRCS2) -lmlx -framework OpenGL -framework AppKit libft/libft.a
	@mkdir obj
	@mv *.o obj/
	@echo "\033[32mFdF compiled [ ✔ ]"

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@echo "\033[32mFdF cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)

re: fclean all
