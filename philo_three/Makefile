NAME		=	philo_three

SRC			=	act.c\
				init.c \
				print_state.c \
				prm_setup.c \
				time_utils.c\
				num_to_buf.c \
				free_data.c\
				main.c
BIN			=	./bin
OBJ			=	$(addprefix $(BIN)/, $(SRC:c=o))
DEP			=	$(OBJ:%.o=%.d)
INCLUDE		=	philo_three.h
LIB			=	-lpthread
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(BIN)/%.o:./%.c $(INCLUDES) | $(BIN)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
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
