/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:45:26 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 14:33:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	img_destroy(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}
