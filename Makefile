# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:22:50 by ahavu             #+#    #+#              #
#    Updated: 2025/03/21 14:30:59 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= client
NAME_SRV	:= server

LIBFT		:= libft_plus.a
LIBFT_PATH	:= incl/libft_plus/

SOURCES_PATH	:= sources/
SOURCES_NAME	:= $(SOURCES_PATH)client.c
SOURCES_SRV		:= $(SOURCES_PATH)server.c 

OBJECTS_NAME	:= $(SOURCES_NAME:.c=.o)
OBJECTS_SRV		:= $(SOURCES_SRV:.c=.o)
HEADERS := incl/minitalk.h

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I ./incl

all: $(LIBFT) $(NAME) $(NAME_SRV)

$(LIBFT):
	@echo "\033[36mmaking libft...\033[0m"
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJECTS_NAME) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS_NAME) $(LIBFT_PATH)libft_plus.a \
		-o $(NAME)

$(NAME_SRV): $(LIBFT) $(OBJECTS_SRV) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS_SRV) $(LIBFT_PATH)libft_plus.a \
		 -o $(NAME_SRV)
	@echo "\033[36m---minitalk compiled!---\033[0m"

clean:
	rm -rf $(OBJECTS_NAME) $(OBJECTS_SRV)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME) $(NAME_SRV)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[36m---everything cleaned!---\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
