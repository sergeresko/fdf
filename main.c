/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/15 21:29:56 by syeresko         ###   ########.fr       */
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

void		legend(void *mlx_ptr, void *win_ptr, int color)
{
	mlx_string_put(mlx_ptr, win_ptr, 200, 20, color,
		"     shift:    (arrows)");
	mlx_string_put(mlx_ptr, win_ptr, 200, 60, color,
		"      zoom:    + -");
	mlx_string_put(mlx_ptr, win_ptr, 1500, 20, color,
		"    rotate:    x s  y 6  z a");
	mlx_string_put(mlx_ptr, win_ptr, 1500, 60, color,
		"  altitude:    * /  (numpad)");
	mlx_string_put(mlx_ptr, win_ptr, 200, 1120, color,
		"projection:    o c");
	mlx_string_put(mlx_ptr, win_ptr, 200, 1160, color,
		" viewpoint:    + -  (numpad)");
	mlx_string_put(mlx_ptr, win_ptr, 1500, 1120, color,
		"     color:    1 2 3 4 5");
	mlx_string_put(mlx_ptr, win_ptr, 1500, 1160, color,
		"      exit:    esc");
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
	t_point3d const	a = to3d(fdf, x, y, param);
	t_pixel			p;

	p = proj_central(a, param);
	if (a.z >= param->origin.z)
		p.color = 0;
	return (p);
}

int		key_press_shift(int keycode, t_param *param)
{
	if (keycode != KEY_ARROW_LEFT && keycode != KEY_ARROW_RIGHT &&
		keycode != KEY_ARROW_DOWN && keycode != KEY_ARROW_UP)
		return (-1);
	if (keycode == KEY_ARROW_LEFT)
		param->origin.x += 25 / param->zoom;
	else if (keycode == KEY_ARROW_RIGHT)
		param->origin.x -= 25 / param->zoom;
	else if (keycode == KEY_ARROW_DOWN)
		param->origin.y -= 25 / param->zoom;
	else if (keycode == KEY_ARROW_UP)
		param->origin.y += 25 / param->zoom;
	return (0);
}

int		key_press_zoom(int keycode, t_param *param)
{
	if (keycode != KEY_EQUALS && keycode != KEY_MINUS)
		return (-1);
	if (keycode == KEY_EQUALS)
		param->zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		param->zoom /= 1.1;
	return (0);
}

int		key_press_rotate(int keycode, t_param *param)
{
	int		axis;
	double	angle;

	if (keycode != KEY_X && keycode != KEY_S && keycode != KEY_Y &&
		keycode != KEY_6 && keycode != KEY_Z && keycode != KEY_A)
		return (-1);
	if (keycode == KEY_X || keycode == KEY_S)
		axis = AXIS_X;
	else if (keycode == KEY_Y || keycode == KEY_6)
		axis = AXIS_Y;
	else
		axis = AXIS_Z;
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		angle = M_PI / 30.;
	else
		angle = -M_PI / 30.;
	rotate(&(param->rot), axis, angle);
	return (0);
}

int		key_press_color(int keycode, t_param *param)
{
	if (keycode != KEY_1 && keycode != KEY_2 &&
		keycode != KEY_3 && keycode != KEY_4 && keycode != KEY_5)
		return (-1);
	if (keycode == KEY_1)
		param->color = 0xffffff;
	else if (keycode == KEY_2)
		param->color = 0xff906b;
	else if (keycode == KEY_3)
		param->color = 0xfde74c;
	else if (keycode == KEY_4)
		param->color = 0xb9ff56;
	else if (keycode == KEY_5)
		param->color = 0x5bc0eb;
	return (0);
}

int		key_press_altitude(int keycode, t_param *param)
{
	if (keycode != KEY_NUM_ASTERISK && keycode != KEY_NUM_SLASH)
		return (-1);
	if (keycode == KEY_NUM_ASTERISK)
		++(param->altitude);
	else if (keycode == KEY_NUM_SLASH)
		--(param->altitude);
	return (0);
}

int		key_press_z0(int keycode, t_param *param)
{
	if (keycode != KEY_NUM_PLUS && keycode != KEY_NUM_MINUS)
		return (-1);
	if (keycode == KEY_NUM_PLUS)
		param->origin.z *= 1.1;
	else if (keycode == KEY_NUM_MINUS)
		param->origin.z /= 1.1;
	return (0);
}

int		key_press_projection(int keycode, t_param *param)
{
	if (keycode != KEY_O && keycode != KEY_C)
		return (-1);
	if (keycode == KEY_O)
		param->proj = proj_o;
	else if (keycode == KEY_C)
		param->proj = proj_c;
	return (0);
}

int		key_press(int keycode, void *hook_param)
{
	t_hook_param	*p;

	p = (t_hook_param *)hook_param;
//	ft_printf("%3d\n", keycode);
	if (keycode == KEY_ESCAPE)
	{
//		system("leaks a.out");
		exit(0);
	}

	t_param *const	param = ((t_hook_param *)hook_param)->param;

	if (key_press_zoom(keycode, param) == 0 ||
		key_press_rotate(keycode, param) == 0 ||
		key_press_projection(keycode, param) == 0 ||
		key_press_shift(keycode, param) == 0 ||
		key_press_altitude(keycode, param) == 0 ||
		key_press_color(keycode, param) == 0 ||
		key_press_z0(keycode, param) == 0)
	{
		img_destroy(p->img);
		p->img = img_init(p->mlx_ptr, 2000, 1000);
		img_fdf(p->img, p->fdf, p->param);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img->img_ptr, 0, 100);
	}
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
	param.zoom = 0.8 * fmin(1000 / (20. * fdf.height), 2000 / (20. * fdf.width));
	param.rot[0][0] = 1.;//sqrt(1. / 2.);
	param.rot[0][1] = 0.;
	param.rot[0][2] = 0.;//-sqrt(1. / 2.);
	param.rot[1][0] = 0.;//sqrt(1. / 6.);
	param.rot[1][1] = 1.;//sqrt(2. / 3.);
	param.rot[1][2] = 0.;//sqrt(1. / 6.);
	param.rot[2][0] = 0.;//sqrt(1. / 3.);
	param.rot[2][1] = 0.;//-sqrt(1. / 3.);
	param.rot[2][2] = 1.;//sqrt(1. / 3.);
	param.altitude = 5;
	param.origin.x = 1000.;
	param.origin.y = 500.;
	param.origin.z = 20. * ft_max(fdf.width, fdf.height);
	param.proj = proj_o;

	void	*mlx_ptr = mlx_init();
	t_img	*img = img_init(mlx_ptr, 2000, 1000);

	img_fdf(img, &fdf, &param);

	void	*win_ptr = mlx_new_window(mlx_ptr, 2000, 1200, "FdF - syeresko");

//	printf("window created\n");
	legend(mlx_ptr, win_ptr, 0xffffff);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img_ptr, 0, 100);

	t_hook_param	hook_param = {mlx_ptr, win_ptr, img, &fdf, &param};

	mlx_hook(win_ptr, 2, 5, key_press, &hook_param);
//	mlx_key_hook(win_ptr, key_hook, &hook_param);
//	mlx_do_key_autorepeaton(mlx_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
