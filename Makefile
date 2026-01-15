# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:02:49 by rsilva-e          #+#    #+#              #
#    Updated: 2026/01/15 22:48:19 by rsilva-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
NASM		= nasm
NASMFLAGS	= -f elf64 -g
RM			= rm -rf
MAIN = main.c
TEST = test

SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_strdup.s \
				ft_write.s	\
				ft_read.s

BONUS_SRCS	=	ft_atoi_base.s \
				ft_list_size.s \
				ft_list_push_front.s \
				ft_list_sort.s \
				ft_list_remove_if.s

OBJS = $(SRCS:.s=.o)
			
BONUS_OBJS = $(BONUS_SRCS:.s=.o)

all: $(NAME) #$(TEST)

%.o: %.s
	$(NASM) $(NASMFLAGS)  $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

$(TEST): $(NAME) $(MAIN) 
	gcc -Wall -Wextra -Werror -fPIE $(MAIN) -L. -lasm -o $(TEST)

bonus: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re











