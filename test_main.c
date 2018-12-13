#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_fdf.h"

int		test_paint(t_img *img)
{
	int const	max_i = (img->width < img->height) ? img->width : img->height;

	for (int i = 0; i < max_i; ++i)
	{
		t_pixel		p = {i * i % img->width, 3 * i % img->height, 0xffffff};

		img_pixel_put(img, p);
	}
	for (int i = 0; i < 5; ++i)
	{
		t_pixel		p = {img->width / 5 * i, 0, 0xff00ff};
		t_pixel		q = {img->width / 5 * (5 - i), img->height - 1, 0x00ffff};

		img_line(img, p, q);
	}
	for (int i = 0; i < 5; ++i)
	{
		t_pixel		p = {img->width - 1, img->height / 5 * i, 0xff00ff};
		t_pixel		q = {0, img->height / 5 * (5 - i), 0x00ffff};

		img_line(img, p, q);
	}
//	printf("painting finished\n");
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	printf("%3d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr = mlx_init();
	t_img	*img = img_init(mlx_ptr, 200, 200);

	test_paint(img);

	void	*win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hello!");

//	printf("window created\n");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img_ptr, 200, 200);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img_ptr, -100, -100);

	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
