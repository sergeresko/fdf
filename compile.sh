gcc -Wall -Wextra -Werror \
	-I /usr/local/include \
	int_list.c \
	parse.c \
	to3d.c \
	rotations.c \
	img_init.c \
	img_destroy.c \
	img_pixel_put.c \
	img_line.c \
	img_fdf.c \
	main.c \
	-L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit \
	-I ~/Documents/libft_gnl_printf -L ~/Documents/libft_gnl_printf -lft
