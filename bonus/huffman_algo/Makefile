# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 00:35:24 by ariard            #+#    #+#              #
#    Updated: 2017/06/09 20:07:59 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	compress

CC		=	gcc
FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=	
SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/


SRC_BASE	=	\
compress.c\
huffman_tree.c\
main.c\
read_debug.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

$(NAME) : $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $@ \033[0m\033[K\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)

clean: cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:	clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

