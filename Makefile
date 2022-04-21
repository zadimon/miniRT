NAME				=	miniRT

LIBS				=	-lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INC					=	-I$(HEADER_DIR)

HEADER_DIR			=	./includes/
HEADER				=	$(HEADER_DIR)miniRT.h

MLX					=	$(MLX_DIR)libmlx.a
MLX_DIR				=	./mlx/

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	./libft/

SRC					=	$(shell ls srcs/main/*.c) \
			  			$(shell ls srcs/parser/*.c) \
						$(shell ls srcs/rendering/*.c) \
						$(shell ls srcs/vector/*.c) \
						$(shell ls srcs/key_control/*.c)

OBJ_DIR				=	./objs/
OBJ					=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS				=	-Wall -Wextra -Werror -g -Imlx
CC					=	gcc
RM					=	rm -rf

.PHONY:				all clean fclean re

all:				$(NAME)

$(NAME):			$(LIBFT) $(MLX) $(OBJ) $(OBJ_DIR) Makefile
					$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c	$(HEADER)
					mkdir -p $(dir $@)
					$(CC) $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
					$(MAKE) -C $(LIBFT_DIR)

$(MLX):
					$(MAKE) -C $(MLX_DIR)

clean:
					$(MAKE) clean -C $(MLX_DIR)
					$(MAKE) clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(MLX)
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)

re:					fclean all