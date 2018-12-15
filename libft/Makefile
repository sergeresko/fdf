# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 14:52:25 by syeresko          #+#    #+#              #
#    Updated: 2018/12/09 20:16:27 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	\
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c \
	ft_strsplit.c \
	ft_strsplit_lst.c \
	ft_strtrim.c \
	ft_itoa.c \
	\
	ft_putchar.c ft_putchar_fd.c \
	ft_putnchar.c ft_putnchar_fd.c \
	ft_putstr.c ft_putstr_fd.c \
	ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c \
	\
	ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_striteri.c \
	ft_lstmap.c ft_strmapi.c \
	ft_lstlen.c \
	\
	get_next_line.c \
	\
	ft_min.c ft_max.c ft_abs.c \
	ft_floor_l.c \
	ft_utf8_len.c \
	ft_parse_number.c \
	\
	ft_printf.c \
	pf_parse_format.c \
	pf_converters.c \
	pf_count_zeroes.c \
	pf_print_alpha.c \
	pf_print_signed.c pf_print_unsigned.c \
	pf_print_pointer.c \
	pf_print_float.c

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c libft.h
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
