/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:16:35 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/13 15:16:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
//#include <stdio.h>
#include <stdlib.h>
#include "my_fdf.h"

t_img		*img_init(void *mlx_ptr, int width, int height)
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
		/*
		printf("img_init:(%p, %d, %d):\n", mlx_ptr, width, height);
		printf("  img = %p\n", img);
		printf("  img->mlx_ptr = %p\n", img->mlx_ptr);
		printf("  img->img_ptr = %p\n", img->img_ptr);
		printf("  img->width = %d\n", img->width);
		printf("  img->height = %d\n", img->height);
		printf("  img->data = %p\n", img->data);
		printf("  img->bits_per_pixel: %d\n", img->bits_per_pixel);
		printf("  img->size_line: %d\n", img->size_line);
		printf("  img->endian: %d\n", img->endian);
		*/
	}
	return (img);
}
