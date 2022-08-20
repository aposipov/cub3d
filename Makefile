# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 18:11:15 by lchristi          #+#    #+#              #
#    Updated: 2022/07/29 18:11:23 by lchristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3d
LIBFT_A = 	libft/libft.a
CC = 		gcc
WFLAGS = 	-Wall -Wextra -Werror
MLXFLAG =	-lmlx -lX11 -lXext
INCFLAG = 	-I ./inc/ -I ./libft/inc
HEADER = 	./inc/

SRC =		src/main.c\
			src/gnl/get_next_line.c src/gnl/get_next_line_utils.c\
			src/init.c src/start.c\

OBJ = 		$(patsubst %.c, %.o, $(SRC))

RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

.PHONY:	all clean fclean re norm

all:		$(LIBFT_A) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(WFLAGS) $(OBJ) $(LIBFT_A) $(MLXFLAG) -o $(NAME)
			@echo -e "$(GREEN)\t\n cub3d compiled!\n $(NC)"

$(LIBFT_A):
			make -C libft/

%.o : %.c 	Makefile $(HEADER)
			$(CC) $(INCFLAG) $(WFLAGS) -c $< -o $@

clean:
			make -C libft clean
			rm -f $(OBJ)
			@echo -e "$(RED)*.o files is clean!$(NC)"

fclean:		clean
			make -C libft fclean
			rm -f $(NAME)
			@echo -e "$(RED)All files is clean!$(NC)"

re:			fclean all

norm:
			@norminette libft/ $(HEADER) $(SRC)
			@echo -e "$(GREEN)\t\n Norminette is OK!\n $(NC)"
