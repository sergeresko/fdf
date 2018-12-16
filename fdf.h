/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:27:27 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 16:49:46 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
**	rlist
*/

typedef struct	s_rows
{
	int				*row;
	struct s_rows	*next;
}				t_rows;

int				rlist_push(t_rows **list, int *row);
void			rlist_delete(t_rows *list);

/*
**	fdf
*/

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**values;
}				t_fdf;

t_fdf			*fdf_parse(int fd);

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

# define AXIS_X				0
# define AXIS_Y				1
# define AXIS_Z				2

void			rotate(t_matrix *rot, int axis, double angle);

typedef struct	s_hook_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_fdf		*fdf;
	t_param		*param;
}				t_hook_param;

# define KEY_X				7
# define KEY_S				1
# define KEY_Y				16
# define KEY_6				22
# define KEY_Z				6
# define KEY_A				0
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_EQUALS			24
# define KEY_MINUS			27
# define KEY_NUM_ASTERISK	67
# define KEY_NUM_SLASH		75
# define KEY_NUM_PLUS		69
# define KEY_NUM_MINUS		78
# define KEY_O				31
# define KEY_C				8
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_UP		126
# define KEY_ESCAPE			53

# define COLOR_WHITE		0xeeeeee
# define COLOR_RED			0xd01919
# define COLOR_YELLOW		0xffe900
# define COLOR_GREEN		0x19d800
# define COLOR_BLUE			0x0befe0

int				key_press(int keycode, void *hook_param);

t_pixel			proj_o(t_fdf *fdf, int x, int y, t_param *param);
t_pixel			proj_c(t_fdf *fdf, int x, int y, t_param *param);

#endif
