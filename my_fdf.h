/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:27:27 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/14 18:57:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FDF_H
# define MY_FDF_H

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

t_img			*img_init(void *mlx_ptr, int width, int height);
void			img_destroy(t_img *img);

void			img_pixel_put(t_img *img, t_pixel p);

void			img_line(t_img *img, t_pixel p, t_pixel q);

/*
**	int_list
*/

typedef struct	s_int_list
{
	int					*array;
	struct s_int_list	*next;
}				t_int_list;

int				list_push(t_int_list **list, int *array);
void			list_delete(t_int_list *list);

/*
**	fdf
*/

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**values;
}				t_fdf;

int				fdf_parse(int fd, t_fdf *fdf);

typedef struct	s_point3d
{
	double		x;
	double		y;
	double		z;
}				t_point3d;

typedef double	t_matrix[3][3];

typedef struct	s_param
{
	int			color;
	double		zoom;
	t_matrix	rot;
	int			altitude;
	t_point3d	origin;
//	t_pixel		origin;
	t_pixel		(*proj)(t_fdf *fdf, int x, int y, struct s_param *param);
}				t_param;

void			img_fdf(t_img *img, t_fdf *fdf, t_param *param);

# define AXIS_X		0
# define AXIS_Y		1
# define AXIS_Z		2

void			rotate(t_matrix *rot, int axis, double angle);

typedef struct	s_hook_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_fdf		*fdf;
	t_param		*param;
}				t_hook_param;

#endif
