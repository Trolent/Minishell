# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 12:40:59 by trolland          #+#    #+#              #
#    Updated: 2025/02/06 08:19:29 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
CC=cc
CFLAGS= -Wall -Wextra -Werror 

# ---------------------------------------------------------------------------- #
# ----------------------------------- SRCS ----------------------------------- #
# ---------------------------------------------------------------------------- #
SRC= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c \
	\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	\
	ft_printf.c putnbr_base.c ft_putchar.c ft_putnbr.c ft_putnbr.c ft_putstr.c \
	\
	ft_swap.c get_next_line.c ft_max.c ft_min.c ft_split_multi.c ft_free_tab.c \
	ft_atoll.c ft_islower.c ft_isupper.c ft_int_xor_swap.c \
	check_last_characters.c count_words.c count_words_sep.c ft_round.c \
	is_in_string.c ft_isposneg.c ft_iswhitespace.c ft_strcmp.c

OBJ= $(SRC:.c=.o)
HEADER= ./

ASCII_ART = \
"\n              .--.           .---.        .-.    \n"\
"         .---|--|   .-.     | \033[1;32mL\033[0m |  .---. |~|    .--.   \n"\
"      .--|===|is|---|_|--.__| \033[1;32mI\033[0m |--|:::| |~|-==-|==|---. \n"\
"      |%%|STR|as|===| |~~|%%| \033[1;32mB\033[0m |--|   |_|~|ATOI|  |___|-. \n"\
"      |  |   |ci|===| |==|  | \033[1;32mF\033[0m |  |:::|=| |    |FD|---|=| \n"\
"      |  |   |i.|   |_|__|  | \033[1;32mT\033[0m |__|   | | |    |  |___| | \n"\
"      |~~|===|--|===|~|~~|%%|~~~|--|:::|=|~|----|==|---|=| \n"\
"      ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-' \n"


all : $(NAME)

%.o : %.c
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) -I $(HEADER) -c $^ $(CFLAGS) -o $@
# @$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo $(ASCII_ART)
	@echo "Creating libft's library..."
	@ar rc $(NAME) $(OBJ)

clean :
	@echo "Cleaning libft's object files..."
	@rm -rf $(OBJ)

fclean : clean
	@echo "Cleaning libft's library..."
	@rm -rf $(NAME)

re : fclean all

norm:
	@echo 'Checking header files...'
	@output_header=$$(norminette -R CheckDefine *.h); \
	echo "$$output_header" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	echo 'Checking source files...'; \
	output_source=$$(norminette -R CheckForbiddenSourceHeader *.c); \
	echo "$$output_source" | awk '/Error/ {print "\033[0;31m" $$0 "\033[0m"}'; \
	total_errors=$$(echo "$$output_header $$output_source" | grep -c 'Error:'); \
	if [ $$total_errors -gt 0 ]; then \
	    echo "\033[0;31m$$total_errors errors found\033[0m"; \
	else \
	    echo "\033[0;32mNo norminette error in Libft\033[0m"; \
	fi

.PHONY: all clean fclean re norm so
