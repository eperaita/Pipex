NAME = pipex

CC = clang
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

SRC = pipex_multiple.c\
	  pipex_errors.c\

SRC_BONUS = pipex_multiple_doc.c\
			pipex_errors_doc.c\
			pipex_doc.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) $(INCLUDES) -o $(NAME)

$(OBJ): $(addprefix $(SRC_DIR), $(SRC))
	@$(CC) $(CFLAGS) -c $^
	@mv $(OBJ) $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(INCLUDES): libft/*.c
	@$(MAKE) -C libft/
	
bonus: $(OBJ_BONUS) $(INCLUDES) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR), $(OBJ_BONUS)) $(INCLUDES) -o $(NAME)
	
$(OBJ_BONUS): $(addprefix $(SRC_DIR), $(SRC_BONUS))
	@$(CC) $(CFLAGS) -c $^
	@mv $(OBJ_BONUS) $(OBJ_DIR)

clean:
	@$(MAKE) -C libft/ clean
	@$(RM) $(addprefix $(OBJ_DIR), $(OBJ)) 

fclean: clean
	@$(RM) $(NAME) libft.a

re:	fclean all

.PHONY: all clean fclean re bonus
