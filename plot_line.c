#include "mlx.h"
#include "libft.h"
#include <unistd.h>		//	for sleep
#include "get_next_line.h"

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_param;

void	*mlx_ptr;
void	*win_ptr;

typedef struct	s_pixel
{
	int		x;
	int		y;
	int		color;
}				t_pixel;

typedef struct	s_point3d
{
	double	x;
	double	y;
	double	z;
}				t_point3d;

int		ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

int		rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return ((int)red << 16 | (int)green << 8 | (int)blue);
}

void	plot_line_low(t_pixel p, t_pixel q)
{
	int const	dx = q.x - p.x;
	int const	dy = ft_abs(q.y - p.y);
	int const	dir = (p.y < q.y) ? 1 : -1;
	int			error;

	error = 0;
	while (p.x <= q.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xffffff);
		error += dy;
		if (2 * error >= dx)
		{
			p.y += dir;
			error -= dx;
		}
		p.x += 1;
	}
}

void	plot_line_high(t_pixel p, t_pixel q)
{
	int const	dx = ft_abs(q.x - p.x);
	int const	dy = q.y - p.y;
	int const	dir = (p.x < q.x) ? 1 : -1;
	int			error;

	error = 0;
	while (p.y <= q.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xffffff);
		error += dx;
		if (2 * error >= dy)
		{
			p.x += dir;
			error -= dy;
		}
		p.y += 1;
	}
}

void	plot_line(t_pixel p, t_pixel q)
{
	if (ft_abs(q.y - p.y) < ft_abs(q.x - p.x))
	{
		if (p.x < q.x)
			plot_line_low(p, q);
		else
			plot_line_low(q, p);
	}
	else
	{
		if (p.y < q.y)
			plot_line_high(p, q);
		else
			plot_line_high(q, p);
	}
}

int		deal_key(int key, void *param)
{
	t_param		*p;

	p = (t_param *)param;
	ft_putnbr(key);
	ft_putchar('\n');
	for (int i = 0; i < 600; ++i)
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, i, key * 2, rgb(i * key, i * i, key * key));
	return (0);
}

void	test(void)
{
	t_pixel		p;
	t_pixel		q;

	p.x = 400;
	p.y = 400;
	q.x = 400;
	q.y = 100;
	plot_line(p, q);
}

int		parse()
{
	int		fd;
	char	*line;

	fd = open("map.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (line)
			free(line);
	}
	close(fd);
	return (0);
}

int		main(void)
{
	int const	size_x = 600;
	int const	size_y = 600;
	int const	c[] = {100, 200, 300, 400, 500};
	t_param		param;

	parse();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "mlx 42");

	for (int i = 0; i < 5; ++i)
	{
		t_pixel		p;
		t_pixel		q;

		p.x = c[i];
		p.y = c[0];
		q.x = c[4 - i];
		q.y = c[4];
		plot_line(p, q);
		p.x = c[0];
		p.y = c[i];
		q.x = c[4];
		q.y = c[4 - i];
		plot_line(p, q);
	}

//	test();
	param.mlx_ptr = mlx_ptr;
	param.win_ptr = win_ptr;
	mlx_key_hook(param.win_ptr, deal_key, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
