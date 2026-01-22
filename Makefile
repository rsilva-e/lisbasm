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
RM			= rm -rf

TEST = test

MAIN = main.c \
	   mandatory/mandatory_test.c


SRCS		=	mandatory/ft_strlen.s \
				mandatory/ft_strcpy.s \
				mandatory/ft_strcmp.s \
				mandatory/ft_strdup.s \
				mandatory/ft_write.s	\
				mandatory/ft_read.s

BONUS_SRCS	=	bonus/ft_atoi_base.s \
				bonus/ft_list_size.s \
				bonus/ft_list_push_front.s \
				bonus/ft_list_sort.s \
				bonus/ft_list_remove_if.s

OBJS = $(SRCS:.s=.o)
			
BONUS_OBJS = $(BONUS_SRCS:.s=.o)

all: $(NAME) #$(TEST)

%.o: %.s
	$(NASM) $(NASMFLAGS)  $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

$(TEST): $(NAME) $(MAIN) 
	gcc -Wall -Wextra -Werror  $(MAIN) -L. -lasm -o $(TEST)

bonus: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re











