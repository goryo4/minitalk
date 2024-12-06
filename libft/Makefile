# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygorget <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 17:11:37 by ygorget           #+#    #+#              #
#    Updated: 2024/10/21 15:54:58 by ygorget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
COMP=ar
FLAGS=-Wall -Werror -Wextra
SRC= ft_atoi.c\
     ft_bzero.c\
     ft_calloc.c\
     ft_isalnum.c\
     ft_isascii.c\
     ft_isalpha.c\
     ft_isdigit.c\
     ft_isprint.c\
     ft_memchr.c\
     ft_memcmp.c\
     ft_memcpy.c\
     ft_memmove.c\
     ft_memset.c\
     ft_strchr.c\
     ft_strdup.c\
     ft_strlcat.c\
     ft_strlcpy.c\
     ft_strlen.c\
     ft_strncmp.c\
     ft_strnstr.c\
     ft_strrchr.c\
     ft_tolower.c\
     ft_toupper.c\
     ft_substr.c\
     ft_strjoin.c\
     ft_strtrim.c\
     ft_split.c\
     ft_itoa.c\
     ft_strmapi.c\
     ft_striteri.c\
     ft_putchar_fd.c\
     ft_putstr_fd.c\
     ft_putendl_fd.c\
     ft_putnbr_fd.c\
     ft_printf.c\
     ft_printf_utils.c\
     get_next_line.c\
     get_next_line_utils.c\

SRC_BONUS= ft_lstnew_bonus.c\
           ft_lstadd_front_bonus.c\
           ft_lstsize_bonus.c\
           ft_lstlast_bonus.c\
           ft_lstadd_back_bonus.c\
           ft_lstdelone_bonus.c\
           ft_lstclear_bonus.c\
           ft_lstiter_bonus.c\
           ft_lstmap_bonus.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS= $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME) $(OBJ_BONUS)
	$(COMP) -rc $(NAME) $(OBJ_BONUS)
	
$(NAME): $(OBJ)
	$(COMP) -rc $(NAME) $(OBJ)
	
%.o : %.c
	cc $(FLAGS) -c $< -o $@
	
clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re 
