# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 14:57:37 by bsailor           #+#    #+#              #
#    Updated: 2021/04/24 15:36:12 by bsailor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =  ft_memset.c ft_strlen.c ft_strlcpy.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_strlcat.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_strncmp.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c

LIST_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(patsubst %.c, %.o, $(LIST))
OBJ_B = $(patsubst %.c, %.o, $(LIST_B))

HEAD = libft.h

FLAGS =	-Wall -Wextra -Werror

all : $(NAME)

$(NAME)	: $(OBJ) $(HEAD)
	ar rcs $(NAME) $?

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@

bonus :
	@make OBJ="$(OBJ_B)" all

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean	: clean
	rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re bonus
		
