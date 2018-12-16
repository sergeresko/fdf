/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 17:18:11 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>			// for malloc
#include "libft.h"			// for ft_max
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

static t_param	*param_init(t_fdf const *fdf)
{
	t_param		*param;

	param = (t_param *)malloc(sizeof(t_param));
	param->color = COLOR_YELLOW;
	param->zoom = 0.8 * fmin(1000 / (20. * fdf->height), 2000 / (20. * fdf->width));
	param->rot[0][0] = 1.;//sqrt(1. / 2.);
	param->rot[0][1] = 0.;
	param->rot[0][2] = 0.;//-sqrt(1. / 2.);
	param->rot[1][0] = 0.;//sqrt(1. / 6.);
	param->rot[1][1] = 1.;//sqrt(2. / 3.);
	param->rot[1][2] = 0.;//sqrt(1. / 6.);
	param->rot[2][0] = 0.;//sqrt(1. / 3.);
	param->rot[2][1] = 0.;//-sqrt(1. / 3.);
	param->rot[2][2] = 1.;//sqrt(1. / 3.);
	param->altitude = 5;
	param->origin.x = 1000.;
	param->origin.y = 500.;
	param->origin.z = 20. * ft_max(fdf->width, fdf->height);
	param->proj = proj_o;
	return (param);
}

static void		put_legend(void *mlx_ptr, void *win_ptr, int color)
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

int				main(int argc, char **argv)
{
	int				fd;
	t_hook_param	hp;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	hp.fdf = fdf_parse(fd);
	close(fd);
//	ft_printf("fdf_parse returned %d\n", r);
//	system("leaks a.out");	//////////////////
	if (hp.fdf == NULL)
		return (0);
//	print_fdf(&fdf);
	hp.param = param_init(hp.fdf);
	hp.mlx_ptr = mlx_init();
	hp.img = img_init(hp.mlx_ptr, 2000, 1000);
	img_fdf(hp.img, hp.fdf, hp.param);
	hp.win_ptr = mlx_new_window(hp.mlx_ptr, 2000, 1200, "FdF - syeresko");
	put_legend(hp.mlx_ptr, hp.win_ptr, 0xffffff);
	mlx_put_image_to_window(hp.mlx_ptr, hp.win_ptr, hp.img->img_ptr, 0, 100);
	mlx_hook(hp.win_ptr, 2, 5, key_press, &hp);
	mlx_loop(hp.mlx_ptr);
	return (0);
}
