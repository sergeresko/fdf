/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:45:26 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/14 15:17:15 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "my_fdf.h"
#include <stdlib.h>

void	img_destroy(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}
