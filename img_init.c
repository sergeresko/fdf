/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:16:35 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 14:33:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"
#include "mlx.h"
#include <stdlib.h>

t_img	*img_init(void *mlx_ptr, int width, int height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img)
	{
		img->mlx_ptr = mlx_ptr;
		img->img_ptr = mlx_new_image(mlx_ptr, width, height);
		img->width = width;
		img->height = height;
		img->addr = mlx_get_data_addr(img->img_ptr,
					&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	}
	return (img);
}
