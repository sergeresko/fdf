gcc -Wall -Wextra -Werror \
	-I /usr/local/include \
	ft_abs.c \
	img_init.c \
	img_line.c \
	img_pixel_put.c \
	test_main.c \
	-L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit \
#	-I ~/Documents/libft_1 -L ~/Documents/libft_1 -lft
