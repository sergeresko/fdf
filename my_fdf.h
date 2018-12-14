/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:27:27 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/14 15:08:50 by syeresko         ###   ########.fr       */
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

//int				ft_abs(int n);	//	remove as it's now in libft

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

//# define FDF_SIN		0x1.ac2609b3c576bp-4
//# define FDF_COS		0x1.fd31f94f867c6p-1

typedef double	t_matrix[3][3];

typedef struct	s_param
{
	int			color;
	double		zoom;
	t_matrix	rot;
	int			altitude;
//	t_point3d	origin;
	t_pixel		origin;
	t_pixel		(*proj)(t_fdf *fdf, int x, int y, struct s_param *param);
}				t_param;

void			img_fdf(t_img *img, t_fdf *fdf, t_param *param);

# define AXIS_X		0
# define AXIS_Y		1
# define AXIS_Z		2

//void			rot_x(t_matrix *rot, int dir);
//void			rot_y(t_matrix *rot, int dir);
//void			rot_z(t_matrix *rot, int dir);
/* TODO */
//void			rotate(t_matrix *rot, int axis, double sin_phi, double cos_phi);
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
