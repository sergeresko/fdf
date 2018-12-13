/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:18:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_fdf.h"

void	img_fdf(t_img *img, t_fdf *fdf, t_param *param)
{
	int			x;
	int			y;
	t_pixel		*array;
	t_pixel		p;

	array = (t_pixel *)malloc(fdf->width * sizeof(t_pixel));
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			p = param->proj(fdf, x, y, param);
			if (x)
				img_line(img, p, array[x - 1]);
			if (y)
				img_line(img, p, array[x]);
			array[x] = p;
			++x;
		}
		++y;
	}
	free(array);
}
