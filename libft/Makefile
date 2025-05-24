# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:56:50 by atambo            #+#    #+#              #
#    Updated: 2025/05/24 12:34:15 by mchingi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
NAME =		libft.a
SRCS =		ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putstr.c\
			ft_putlines.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_strchr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_putstr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_strtrim_free.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putnbr_fd.c\
			ft_malloc.c\
			ft_free_p.c\
			ft_free_pp.c\
			ft_split.c\
			ft_perror.c\
			ft_strncpy.c\
			ft_abs.c\
			ft_realloc.c \
			ft_free_array.c \
			ft_atof.c \
			ft_array_size.c\
			ft_split2.c\
			get_next_line.c\
			ft_isspace.c\
			


OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

