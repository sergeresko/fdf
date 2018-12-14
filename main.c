/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/14 15:34:01 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>		// for exit
#include "my_fdf.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

#include <math.h>

void	print_fdf(t_fdf const *fdf)
{
	int		i;
	int		j;

	ft_printf("fdf->width:  %d\n", fdf->width);
	ft_printf("fdf->height: %d\n", fdf->height);
	ft_printf("fdf->values: %p\n", fdf->values);
	if (fdf->values)
	{
		i = 0;
		while (i < fdf->height)
		{
			j = 0;
			while (j < fdf->width)
			{
				ft_printf("%4d", fdf->values[i][j]);
				++j;
			}
			ft_putchar('\n');
			++i;
		}
	}
}

t_point3d	to3d(t_fdf *fdf, int x, int y, t_param *param);		//
t_pixel		proj_ortho(t_point3d a, t_param *param);			//
t_pixel		proj_central(t_point3d a, t_param *param);			//


t_pixel		proj_o(t_fdf *fdf, int x, int y, t_param *param)
{
	return (proj_ortho(to3d(fdf, x, y, param), param));
}

t_pixel		proj_c(t_fdf *fdf, int x, int y, t_param *param)
{
	return (proj_central(to3d(fdf, x, y, param), param));
}

//int		key_press_shift(int keycode, void *hook_param)
//{
//}

int		key_press(int keycode, void *hook_param)
{
	t_hook_param	*p;

	p = (t_hook_param *)hook_param;
//	ft_printf("%3d\n", keycode);
	if (keycode == 53)				//	ESC
	{
		system("leaks a.out");
		exit(0);
	}
	if (keycode == 24)				//	=
		p->param->zoom *= 1.1;
	else if (keycode == 27)			//	-
		p->param->zoom /= 1.1;
	else if (keycode == 7 || keycode == 1 || keycode == 16 || keycode == 22 ||
		keycode == 6 || keycode == 0)
	{
		int		axis;
		double	angle;

		if (keycode == 7 || keycode == 1)			//	x or s
			axis = AXIS_X;
		else if (keycode == 16 || keycode == 22)	//	y or 6
			axis = AXIS_Y;
		else										//	z or a
			axis = AXIS_Z;
		if (keycode == 7 || keycode == 16 || keycode == 6)
			angle = M_PI / 30.;
		else
			angle = -M_PI / 30.;
		rotate(&(p->param->rot), axis, angle);
	}
	else if (keycode == 31)			//	o
		p->param->proj = proj_o;
	else if (keycode == 8)			//	c
		p->param->proj = proj_c;
	else if (keycode == 123)		//	left arrow
		p->param->origin.x -= 25 / p->param->zoom;
	else if (keycode == 124)		//	right arrow
		p->param->origin.x += 25 / p->param->zoom;
	else if (keycode == 125)		//	down arrow
		p->param->origin.y += 25 / p->param->zoom;
	else if (keycode == 126)		//	up arrow
		p->param->origin.y -= 25 / p->param->zoom;
	else if (keycode == 67)			//	num *
		++(p->param->altitude);
	else if (keycode == 75)			//	num	/
		--(p->param->altitude);
	else if (keycode == 18)			//	1
		p->param->color = 0xffffff;
	else if (keycode == 19)			//	2
		p->param->color = 0xffff00;
	else if (keycode == 20)			//	3
		p->param->color = 0x00ffff;
	else if (keycode == 21)			//	4
		p->param->color = 0xff00ff;
	img_destroy(p->img);
	p->img = img_init(p->mlx_ptr, 2000, 1000);
	img_fdf(p->img, p->fdf, p->param);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img->img_ptr, 0, 100);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;
	int		r;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	r = fdf_parse(fd, &fdf);
	close(fd);
//	ft_printf("fdf_parse returned %d\n", r);
	if (r < 0)
		return (0);
//	print_fdf(&fdf);

	t_param	param;
	param.color = 0xffff00;
	param.zoom = 1.;
	param.rot[0][0] = 1;
	param.rot[0][1] = 0;
	param.rot[0][2] = 0;
	param.rot[1][0] = 0;
	param.rot[1][1] = 1;
	param.rot[1][2] = 0;
	param.rot[2][0] = 0;
	param.rot[2][1] = 0;
	param.rot[2][2] = 1;
//	rot_z(&(param.rot), 1);
	param.altitude = 5;
//	param.origin.x = 0.;
//	param.origin.y = 0.;
//	param.origin.z = 0.;
	param.origin.x = 1000;
	param.origin.y = 500;
	param.proj = proj_o;

	void	*mlx_ptr = mlx_init();
	t_img	*img = img_init(mlx_ptr, 2000, 1000);

	img_fdf(img, &fdf, &param);

	void	*win_ptr = mlx_new_window(mlx_ptr, 2000, 1200, "FdF - syeresko");

//	printf("window created\n");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img_ptr, 0, 100);

	t_hook_param	hook_param = {mlx_ptr, win_ptr, img, &fdf, &param};

	mlx_hook(win_ptr, 2, 5, key_press, &hook_param);
//	mlx_key_hook(win_ptr, key_hook, &hook_param);
	mlx_loop(mlx_ptr);
	return (0);
}
