NAME		= libfts.a

ASM		= nasm
ASM_FLAGS	= -f macho64

LC		= ar -rc
IC		= ranlib

MKDIR		= mkdir -p
RM		= /bin/rm -rf

SRC_DIR		= src/
OBJ_DIR		= objs/

SRC_BASE	= \
ft_bzero.s\
ft_strcat.s\
ft_isalpha.s\
ft_isdigit.s\
ft_isalnum.s\
ft_isascii.s\
ft_isprint.s\
ft_toupper.s\
ft_tolower.s\
ft_puts.s\
ft_strlen.s\
ft_memset.s\
ft_memcpy.s\
ft_strdup.s\
ft_cat.s\


SRCS		= $(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_BASE:.s=.o))


all:
	make $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(LC) $(NAME) $(OBJS)			
	$(IC) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.s | $(OBJ_DIR)
	$(ASM) $(ASM_FLAGS) $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
