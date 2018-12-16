/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:17:09 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 16:04:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate(t_matrix *rot, int axis, double angle)
{
	double *const	r1 = (*rot)[(axis < 2) ? (axis + 1) : (axis - 2)];
	double *const	r2 = (*rot)[(axis > 0) ? (axis - 1) : (axis + 2)];
	double const	s = sin(angle);
	double const	c = cos(angle);
	double			tmp;

	tmp = c * r1[0] - s * r2[0];
	r2[0] = s * r1[0] + c * r2[0];
	r1[0] = tmp;
	tmp = c * r1[1] - s * r2[1];
	r2[1] = s * r1[1] + c * r2[1];
	r1[1] = tmp;
	tmp = c * r1[2] - s * r2[2];
	r2[2] = s * r1[2] + c * r2[2];
	r1[2] = tmp;
}
