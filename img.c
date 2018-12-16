/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:45:26 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 16:16:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

void	img_destroy(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}
