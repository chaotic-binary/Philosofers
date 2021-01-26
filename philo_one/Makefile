NAME		=	test #philo_one

SRC			=	ft_swap.c\
				free_data.c \
				init_arrays.c \
				error.c \
				print_state.c \
				prm_setup.c \
				main.c
BIN			=	./bin
OBJ			=	$(addprefix $(BIN)/, $(SRC:c=o))
DEP			=	$(OBJ:%.o=%.d)
INCLUDE		=	philo_one.h
LIB			=	-lpthread
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME)

$(BIN)/%.o:./%.c $(INCLUDES) | $(BIN)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	#make -C ../libft/
	$(CC) $(FLAGS) $(LIB) $^ -o $@

$(BIN):
	@mkdir $(BIN)

-include $(DEP)

clean:
	@rm -rf $(BIN)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all
