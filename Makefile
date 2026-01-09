# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:02:49 by rsilva-e          #+#    #+#              #
#    Updated: 2026/01/08 15:56:07 by rsilva-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
NASM		= nasm
NASMFLAGS	= -f elf64 -g
RM			= rm -rf

SRCS		=	ft_strlen.s \
				ft_strcpy.s

# BONUS_SRCS	=	ft_lstadd_back.c \

OBJS = $(SRCS:.s=.o)
			
BONUS_OBJS = $(BONUS_SRCS:.s=.o)

all: $(NAME)

%.o: %.s
	$(NASM) $(NASMFLAGS)  $< -o $@

$(NAME): $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

bonus: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re