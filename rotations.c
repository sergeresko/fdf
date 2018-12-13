/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:17:09 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/12 21:03:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "my_fdf.h"

/*
void	rot_x(t_matrix *rot, int dir)
{
	double const	sin = (dir > 0) ? FDF_SIN : -FDF_SIN;
	double			tmp;
	int				j;

	j = 0;
	while (j < 3)
	{
		tmp = FDF_COS * (*rot)[1][j] - sin * (*rot)[2][j];
		(*rot)[2][j] = sin * (*rot)[1][j] + FDF_COS * (*rot)[2][j];
		(*rot)[1][j] = tmp;
		++j;
	}
}

void	rot_y(t_matrix *rot, int dir)
{
	double const	sin = (dir > 0) ? FDF_SIN : -FDF_SIN;
	double			tmp;
	int				j;

	j = 0;
	while (j < 3)
	{
		tmp = FDF_COS * (*rot)[0][j] + sin * (*rot)[2][j];
		(*rot)[2][j] = -sin * (*rot)[0][j] + FDF_COS * (*rot)[2][j];
		(*rot)[0][j] = tmp;
		++j;
	}
}

void	rot_z(t_matrix *rot, int dir)
{
	double const	sin = (dir > 0) ? FDF_SIN : -FDF_SIN;
	double			tmp;
	int				j;

	j = 0;
	while (j < 3)
	{
		tmp = FDF_COS * (*rot)[0][j] - sin * (*rot)[1][j];
		(*rot)[1][j] = sin * (*rot)[0][j] + FDF_COS * (*rot)[1][j];
		(*rot)[0][j] = tmp;
		++j;
	}
}
*/

/* TODO */
void	rotate(t_matrix *rot, int axis, double angle)
{
	double *const	r1 = (*rot)[(axis < 2) ? (axis + 1) : (axis - 2)];
	double *const	r2 = (*rot)[(axis > 0) ? (axis - 1) : (axis + 2)];
//	int const		i_2 = (axis > 0) ? (axis - 1) : (axis + 2);
//	int				j;
	double const	s = sin(angle);
	double const	c = cos(angle);
	double			tmp;
/*
	j = 0;
	while (j < 3)
	{
		tmp = cos_phi * (*rot)[i_1][j] - sin_phi * (*rot)[i_2][j];
		(*rot)[i_2][j] = sin_phi * (*rot)[i_1][j] + cos_phi * (*rot)[i_2][j];
		(*rot)[i_1][j] = tmp;
		++j;
	}
*/
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
