# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 06:30:26 by hakawamo          #+#    #+#              #
#    Updated: 2025/07/06 22:39:16 by hakawamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f

SRCS			=	init.c input_check.c linked_list.c others.c \
					push_swap.c push.c r_rotate.c rotate.c \
					sort_utils.c sort.c swap.c

OBJS			= $(SRCS:.c=.o)

LIBFT_DIR		= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re