/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:27:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/13 15:26:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "my_fdf.h"
#include "libft.h"	// for ft_abs

static void	img_line_low(t_img *img, t_pixel p, t_pixel q)
{
	int const	dx = q.x - p.x;
	int const	dy = ft_abs(q.y - p.y);
	int const	dir = (p.y < q.y) ? 1 : -1;
	int			error;

	error = 0;
	while (p.x <= q.x)
	{
		if (p.x >= img->width ||											//
			(p.y < 0 && dir == -1) || (p.y >= img->height && dir == 1))		//
			return ;														//
		if (0 <= p.x && 0 <= p.y && p.y < img->height)						//
			img_pixel_put(img, p);
		error += dy;
		if (2 * error >= dx)
		{
			p.y += dir;
			error -= dx;
		}
		p.x += 1;
	}
}

static void	img_line_high(t_img *img, t_pixel p, t_pixel q)
{
	int const	dx = ft_abs(q.x - p.x);
	int const	dy = q.y - p.y;
	int const	dir = (p.x < q.x) ? 1 : -1;
	int			error;

	error = 0;
	while (p.y <= q.y)
	{
		if (p.y >= img->height ||											//
			(p.x < 0 && dir == -1) || (p.x >= img->height && dir == 1))		//
			return ;														//
		if (0 <= p.y && 0 <= p.x && p.x < img->width)						//
			img_pixel_put(img, p);
		error += dx;
		if (2 * error >= dy)
		{
			p.x += dir;
			error -= dy;
		}
		p.y += 1;
	}
}

void		img_line(t_img *img, t_pixel p, t_pixel q)
{
	if ((p.x < 0 && q.x < 0) || (p.x >= img->width && q.x >= img->width) ||
		(p.y < 0 && q.y < 0) || (p.y >= img->height && q.y >= img->height))
		return ;
	if (ft_abs(q.y - p.y) < ft_abs(q.x - p.x))
		(p.x < q.x) ? img_line_low(img, p, q) : img_line_low(img, q, p);
	else
		(p.y < q.y) ? img_line_high(img, p, q) : img_line_high(img, q, p);
}
