# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:02:49 by rsilva-e          #+#    #+#              #
#    Updated: 2026/01/22 23:35:27 by rsilva-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
NASM		= nasm
NASMFLAGS	= -f elf64 -g
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -rf
TEST		= test
TEST_BONUS	= test_bonus

# SRCS
SRCS		=	$(wildcard mandatory/*.s)
BONUS_SRCS	=	$(wildcard bonus/*.s)

# OBJECTS
OBJS = $(SRCS:.s=.o)
BONUS_OBJS = $(BONUS_SRCS:.s=.o)


# TESTS
MAIN = main.c $(wildcard mandatory/*.c)
MAIN_BONUS   = main_bonus.c $(wildcard mandatory/*.c) $(wildcard bonus/*.c)

all: $(NAME) 

%.o: %.s
	$(NASM) $(NASMFLAGS)  $< -o $@

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS) 

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)  

test: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) -L. -lasm -o $(TEST)

test_bonus: bonus
	$(CC) $(CFLAGS) $(MAIN_BONUS) -L. -lasm -o $(TEST_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST) $(TEST_BONUS)

re: fclean all

.PHONY: all bonus test test_bonus clean fclean re











