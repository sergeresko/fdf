/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:28:21 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/13 13:12:42 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "my_fdf.h"

void	img_pixel_put(t_img *img, t_pixel p)
{
	int const		index = img->size_line * p.y + img->bits_per_pixel / 8 * p.x;
	unsigned const	color = mlx_get_color_value(img->mlx_ptr, p.color);

//	if (p.x < 0 || p.x >= img->width || p.y < 0 || p.y >= img->height)
//		return ;
	//index = img->size_line * p.y + img->bits_per_pixel / 8 * p.x;
	//color = mlx_get_color_value(img->mlx_ptr, p.color);
	*(unsigned *)(img->addr + index) = color;
}
