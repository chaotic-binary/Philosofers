# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 13:18:57 by ttamesha          #+#    #+#              #
#    Updated: 2020/11/23 00:06:07 by ttamesha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
MAIN_SRC	=	ft_atoi.c ft_atof.c \
				ft_bzero.c \
				ft_calloc.c \
				calloc_c.c\
				ft_isalnum.c ft_isalpha.c ft_isspace.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_itoa_base_ll.c\
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				malloc_c.c\
				ft_strchr.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strcmp.c\
				ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c \
				ft_split.c\
				free_arr.c\
				free_and_null.c\
				ft_strmapi.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_base_ll.c\
				ft_pow.c ft_min.c ft_max.c countdigits.c countdigits_base_ll.c\
				stradd.c
MAIN_OBJ	=	$(addprefix $(O_DIR)/, $(MAIN_SRC:.c=.o))
BONUS_SRC	=	ft_lstsize.c \
				ft_lstnew.c ft_lstnew_c.c \
				ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
				ft_dlstnew.c ft_dlstnew_c.c ft_dlstlast.c\
				ft_dlstadd_front.c ft_dlstadd_back.c
BONUS_OBJ	=	$(addprefix $(O_DIR)/, $(BONUS_SRC:.c=.o))
INCLUDES	=	$(NAME:.a=.h)
O_DIR		=	./bin

ifdef WITH_BONUS
SRC = $(BONUS_SRC) $(MAIN_SRC)
OBJ = $(BONUS_OBJ) $(MAIN_OBJ)
else
SRC = $(MAIN_SRC)
OBJ = $(MAIN_OBJ)
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@ar rc $@ $?
	@ranlib $@
	@echo "$(NAME) compiled"

$(O_DIR)/%.o: ./*/%.c $(INCLUDES) | $(O_DIR)
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(O_DIR):
	@mkdir $(O_DIR)

bonus:
	@$(MAKE) WITH_BONUS=1 all

clean:
	@rm -rf $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
