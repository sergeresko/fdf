/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:53:30 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 18:19:48 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

static int	key_press_shift_zoom(int keycode, t_param *param)
{
	if (keycode == KEY_ARROW_LEFT)
		param->origin.x += 25 / param->zoom;
	else if (keycode == KEY_ARROW_RIGHT)
		param->origin.x -= 25 / param->zoom;
	else if (keycode == KEY_ARROW_DOWN)
		param->origin.y -= 25 / param->zoom;
	else if (keycode == KEY_ARROW_UP)
		param->origin.y += 25 / param->zoom;
	else if (keycode == KEY_EQUALS)
		param->zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		param->zoom /= 1.1;
	else
		return (-1);
	return (0);
}

static int	key_press_rotate(int keycode, t_param *param)
{
	int		axis;
	double	angle;

	if (keycode == KEY_X || keycode == KEY_S)
		axis = AXIS_X;
	else if (keycode == KEY_Y || keycode == KEY_6)
		axis = AXIS_Y;
	else if (keycode == KEY_Z || keycode == KEY_A)
		axis = AXIS_Z;
	else
		return (-1);
	if (keycode == KEY_S || keycode == KEY_Y || keycode == KEY_Z)
		angle = M_PI / 30.;
	else
		angle = -M_PI / 30.;
	rotate(&(param->rot), axis, angle);
	return (0);
}

static int	key_press_alt_z0_proj(int keycode, t_param *param)
{
	if (keycode == KEY_NUM_ASTERISK)
		++(param->altitude);
	else if (keycode == KEY_NUM_SLASH)
		--(param->altitude);
	else if (keycode == KEY_NUM_PLUS)
		param->origin.z *= 1.1;
	else if (keycode == KEY_NUM_MINUS)
		param->origin.z /= 1.1;
	else if (keycode == KEY_O)
		param->proj = proj_orthogonal;
	else if (keycode == KEY_C)
		param->proj = proj_central;
	else
		return (-1);
	return (0);
}

static int	key_press_color(int keycode, t_param *param)
{
	if (keycode == KEY_1)
		param->color = COLOR_WHITE;
	else if (keycode == KEY_2)
		param->color = COLOR_RED;
	else if (keycode == KEY_3)
		param->color = COLOR_YELLOW;
	else if (keycode == KEY_4)
		param->color = COLOR_GREEN;
	else if (keycode == KEY_5)
		param->color = COLOR_BLUE;
	else
		return (-1);
	return (0);
}

int			key_press(int keycode, void *hook_param)
{
	t_hook_param *const	hp = (t_hook_param *)hook_param;

	if (keycode == KEY_ESCAPE)
		exit(0);
	if (key_press_shift_zoom(keycode, hp->param) &&
			key_press_rotate(keycode, hp->param) &&
			key_press_alt_z0_proj(keycode, hp->param) &&
			key_press_color(keycode, hp->param))
		return (-1);
	img_destroy(hp->img);
	hp->img = img_init(hp->mlx_ptr, 2000, 1000);
	img_fdf(hp->img, hp->fdf, hp->param);
	mlx_put_image_to_window(hp->mlx_ptr, hp->win_ptr, hp->img->img_ptr, 0, 100);
	return (0);
}
