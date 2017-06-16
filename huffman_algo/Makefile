# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <ariard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 00:35:24 by ariard            #+#    #+#              #
#    Updated: 2017/06/16 18:15:20 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	compress uncompress

CC			=	gcc
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

COM_OBJ		=	$(OBJ_DIR)main.o
UN_OBJ		=	$(OBJ_DIR)main_uncompress.o $(OBJ_DIR)data_uncompress.o

SRC_BASE	=	\
compress.c\
huffman_tree.c\
table.c\
read_debug.c\
do_compress.c\
bit.c\
data_uncompress.c\
main.c\
main_uncompress.c\
hufftree_print.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
OBJS		:=	$(filter-out $(COM_OBJ), $(OBJS))
OBJS		:=	$(filter-out $(UN_OBJ), $(OBJS))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
		@make -C $(LIBFT_DIR)
		@make -j $(NAME)

compress : $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(COM_OBJ)
	@$(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(COM_OBJ) $(FLAGS)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $@ \033[0m\033[K\n"

uncompress : $(LIBFT_LIB) $(OBJ_DIR) $(OBJS) $(UN_OBJ)
	@$(CC) $(OBJS) -o $@ \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(UN_OBJ) $(FLAGS)
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

