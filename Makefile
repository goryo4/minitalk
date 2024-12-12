# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:29:22 by ygorget           #+#    #+#              #
#    Updated: 2024/12/10 15:35:04 by ygorget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S= server
NAME_C= client
NAME_BONUS_S= server_b
NAME_BONUS_C= client_b

CC= cc
FLAGS= -Wall -Werror -Wextra -g

LIBS= libft
LIBA= libft/libft.a

SRC_S= manda/server.c
SRC_C= manda/client.c
SRC_BONUS_S= bonus/server_bonus.c
SRC_BONUS_C= bonus/client_bonus.c

OBJ_S= $(SRC_S:.c=.o)
OBJ_C= $(SRC_C:.c=.o)
OBJ_BONUS_S= $(SRC_BONUS_S:.c=.o)
OBJ_BONUS_C= $(SRC_BONUS_C:.c=.o)

all: $(NAME_S) $(NAME_C)

bonus: $(LIBA) $(NAME_BONUS_S) $(NAME_BONUS_C)

$(LIBA):
	$(MAKE) -C $(LIBS)

$(NAME_S): $(OBJ_S) $(LIBA)
	$(CC) $(FLAGS) $(OBJ_S) -L$(LIBS) -lft -o $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(FLAGS) $(OBJ_C) -L$(LIBS) -lft -o $(NAME_C)

$(NAME_BONUS_S): $(OBJ_BONUS_S)
	$(CC) $(FLAGS) $(OBJ_BONUS_S) -L$(LIBS) -lft -o $(NAME_BONUS_S)

$(NAME_BONUS_C): $(OBJ_BONUS_C)
	$(CC) $(FLAGS) $(OBJ_BONUS_C) -L$(LIBS) -lft -o $(NAME_BONUS_C)

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBS) clean
	rm -f $(OBJ_S) $(OBJ_C) $(OBJ_BONUS_S) $(OBJ_BONUS_C)

fclean: clean
	$(MAKE) -C $(LIBS) fclean
	rm -f $(NAME_S) $(NAME_C) $(NAME_BONUS_S) $(NAME_BONUS_C)

re: fclean all

.PHONY: all clean fclean re
