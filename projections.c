/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:25:52 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 14:36:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

#include <math.h>

static t_point3d	to3d(t_fdf *fdf, int x, int y, t_param *param)
{
	double const	x0 = (fdf->width - 1) / 2.;
	double const	y0 = (fdf->height - 1) / 2.;
	t_point3d		a;
	t_point3d		b;

	a.x = 20. * (x - x0);
	a.y = 20. * (y - y0);
	a.z = 1. * fdf->values[y][x] * param->altitude;
	b.x = param->rot[0][0] * a.x + param->rot[0][1] * a.y + param->rot[0][2] * a.z;
	b.y = param->rot[1][0] * a.x + param->rot[1][1] * a.y + param->rot[1][2] * a.z;
	b.z = param->rot[2][0] * a.x + param->rot[2][1] * a.y + param->rot[2][2] * a.z;
	return (b);
}

static t_pixel		proj_orthogonal(t_point3d a, t_param *param)
{
	t_pixel			p;

//	p.x = param->origin.x + 1000 + (a.x - 1000) * param->zoom;
//	p.y = param->origin.y + 500 + (a.y - 500) * param->zoom;
	p.x = 1000 + (a.x + param->origin.x - 1000) * param->zoom;
	p.y = 500 + (a.y + param->origin.y - 500) * param->zoom;
//	p.x = param->origin.x + a.x * param->zoom;
//	p.y = param->origin.y + a.y * param->zoom;
	p.color = param->color;
	return (p);
}

/*
t_pixel		proj_central(t_point3d a, t_param *param)
{
	double const	r = param->origin.z / (param->origin.z - a.z);
	t_pixel			p;

//	p.x = param->origin.x + 1000 + (r * a.x - 1000) * param->zoom;
//	p.y = param->origin.y + 500 + (r * a.y - 500) * param->zoom;
	p.x = 1000 + (r * a.x + param->origin.x - 1000) * param->zoom;
	p.y = 500 + (r * a.y + param->origin.y - 500) * param->zoom;
	p.color = param->color;
	return (p);
}
*/

static t_pixel		proj_central(t_point3d a, t_param *param)
{
	double const	d = param->origin.z - a.z;
	double const	r = param->origin.z / fmax(d, 0.1);
	t_pixel			p;

	p.x = 1000 + (r * a.x + param->origin.x - 1000) * param->zoom;
	p.y = 500 + (r * a.y + param->origin.y - 500) * param->zoom;
	p.color = (d > 0.) ? param->color: 0;
	return (p);
}

t_pixel		proj_o(t_fdf *fdf, int x, int y, t_param *param)
{
	return (proj_orthogonal(to3d(fdf, x, y, param), param));
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