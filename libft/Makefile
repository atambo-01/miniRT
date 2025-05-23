# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 13:36:51 by mchingi           #+#    #+#              #
#    Updated: 2025/05/20 19:56:57 by mchingi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

SRC	=	ft_atoi.c ft_lstdelone.c ft_putendl_fd.c ft_strncmp.c \
		ft_bzero.c ft_lstiter.c ft_putnbr_fd.c ft_strnstr.c \
		ft_calloc.c ft_lstlast.c ft_putstr_fd.c ft_strrchr.c \
		ft_isalnum.c ft_lstmap.c ft_split.c ft_strtrim.c \
		ft_isalpha.c ft_lstnew.c ft_strchr.c ft_substr.c \
		ft_isascii.c ft_lstsize.c ft_strdup.c ft_tolower.c \
		ft_isdigit.c ft_memchr.c ft_striteri.c ft_toupper.c \
		ft_isprint.c ft_memcmp.c ft_strjoin.c get_next_line.c \
		ft_itoa.c ft_memcpy.c ft_strlcat.c ft_lstadd_back.c \
		ft_memmove.c ft_strlcpy.c ft_lstadd_front.c ft_memset.c \
		ft_strlen.c ft_lstclear.c ft_putchar_fd.c ft_strmapi.c \
		ft_print_c.c ft_print_s.c ft_print_d_i.c ft_print_u.c \
		ft_print_p.c ft_print_xx.c ft_printf.c ft_isspace.c \
		ft_split2.c ft_free_array.c ft_array_size.c ft_atof.c
		

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIB) $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
