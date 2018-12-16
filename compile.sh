gcc -Wall -Wextra -Werror \
	-I /usr/local/include \
	rlist.c \
	parse.c \
	projections.c \
	rotate.c \
	key_press.c \
	img.c \
	img_draw.c \
	main.c \
	-L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit \
	-I ~/Documents/libft_gnl_printf -L ~/Documents/libft_gnl_printf -lft
