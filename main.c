/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/14 19:41:17 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>		// for exit
#include "my_fdf.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

#include <math.h>

/*
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
*/

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

int		key_press_shift(int keycode, t_param *param)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		return (-1);
	if (keycode == 123)				//	left arrow
		param->origin.x += 25 / param->zoom;
	else if (keycode == 124)		//	right arrow
		param->origin.x -= 25 / param->zoom;
	else if (keycode == 125)		//	down arrow
		param->origin.y -= 25 / param->zoom;
	else if (keycode == 126)		//	up arrow
		param->origin.y += 25 / param->zoom;
	return (0);
}

int		key_press_zoom(int keycode, t_param *param)
{
	if (keycode != 24 && keycode != 27)
		return (-1);
	if (keycode == 24)				//	=
		param->zoom *= 1.1;
	else if (keycode == 27)			//	-
		param->zoom /= 1.1;
	return (0);
}

int		key_press_rotate(int keycode, t_param *param)
{
	int		axis;
	double	angle;

	if (keycode != 7 && keycode != 1 && keycode != 16 && keycode != 22 &&
		keycode != 6 && keycode != 0)
		return (-1);
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
	rotate(&(param->rot), axis, angle);
	return (0);
}

int		key_press_color(int keycode, t_param *param)
{
	if (keycode != 18 && keycode != 19 && keycode != 20 && keycode != 21)
		return (-1);
	if (keycode == 18)				//	1
		param->color = 0xffffff;
	else if (keycode == 19)			//	2
		param->color = 0xffff00;
	else if (keycode == 20)			//	3
		param->color = 0x00ffff;
	else if (keycode == 21)			//	4
		param->color = 0xff00ff;
	return (0);
}

int		key_press_altitude(int keycode, t_param *param)
{
	if (keycode != 67 && keycode != 75)
		return (-1);
	if (keycode == 67)				//	num *
		++(param->altitude);
	else if (keycode == 75)			//	num	/
		--(param->altitude);
	return (0);
}

int		key_press_z0(int keycode, t_param *param)
{
	if (keycode != 69 && keycode != 78)
		return (-1);
	if (keycode == 69)				//	num +
		param->origin.z *= 1.1;
	else if (keycode == 78)			//	num -
		param->origin.z /= 1.1;
	return (0);
}

int		key_press_projection(int keycode, t_param *param)
{
	if (keycode != 31 && keycode != 8)
		return (-1);
	if (keycode == 31)				//	o
		param->proj = proj_o;
	else if (keycode == 8)			//	c
		param->proj = proj_c;
	return (0);
}

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

	t_param *const	param = ((t_hook_param *)hook_param)->param;

	if (key_press_zoom(keycode, param) == 0)
		;
	else if (key_press_rotate(keycode, param) == 0)
		;
	else if (key_press_projection(keycode, param) == 0)
		;
	else if (key_press_shift(keycode, param) == 0)
		;
	else if (key_press_altitude(keycode, param) == 0)
		;
	else if (key_press_color(keycode, param) == 0)
		;
	else if (key_press_z0(keycode, param) == 0)
		;
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
	param.origin.x = 1000.;
	param.origin.y = 500.;
	param.origin.z = 20. * ft_max(fdf.width, fdf.height);
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
//	mlx_do_key_autorepeaton(mlx_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
