#include "my_fdf.h"

#include <math.h>

t_point3d	to3d(t_fdf *fdf, int x, int y, t_param *param)
{
	double const	x0 = fdf->width / 2.;
	double const	y0 = fdf->height / 2.;
	t_point3d		a;
	t_point3d		b;

	a.x = 20. * (x - x0);
	a.y = 20. * (y - y0);
	a.z = 1. * fdf->values[y][x] * param->altitude;
	b.x = param->rot[0][0] * a.x + param->rot[0][1] * a.y + param->rot[0][2] * a.z;
	b.y = param->rot[1][0] * a.x + param->rot[1][1] * a.y + param->rot[1][2] * a.z;
	b.z = param->rot[2][0] * a.x + param->rot[2][1] * a.y + param->rot[2][2] * a.z;
//	b.x *= param->zoom;
//	b.y *= param->zoom;
//	b.z *= param->zoom;
	return (b);
}

t_pixel		proj_ortho(t_point3d a, t_param *param)
{
	t_pixel			p;

//	p.x = (int)lrint((param->origin.x + a.x) * param->zoom);
//	p.y = (int)lrint((param->origin.y + a.y) * param->zoom);
	p.x = 1000 + (a.x + param->origin.x - 1000) * param->zoom;
	p.y = 500 + (a.y + param->origin.y - 500) * param->zoom;
//	p.x = param->origin.x + (int)lrint(a.x * param->zoom);
//	p.y = param->origin.y + (int)lrint(a.y * param->zoom);
	p.color = param->color;
	return (p);
}

t_pixel		proj_central(t_point3d a, t_param *param)
{
	double const	r = 1000. / (1000. - a.z);
	t_pixel			p;

//	p.x = param->origin.x + (int)lrint(r * a.x * param->zoom);
//	p.y = param->origin.y + (int)lrint(r * a.y * param->zoom);
	p.x = 1000 + (r * a.x + param->origin.x - 1000) * param->zoom;
	p.y = 500 + (r * a.y + param->origin.y - 500) * param->zoom;
	p.color = param->color;
	return (p);
}
