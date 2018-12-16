/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:06:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 17:25:17 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
**	Adds a new element to the beginning of the list.
**	Returns 0 on success and -1 if memory couldn't be allocated.
*/

int		rlist_push(t_rows **rlist, int *row)
{
	t_rows	*elem;

	elem = (t_rows *)malloc(sizeof(t_rows));
	if (elem)
	{
		elem->row = row;
		elem->next = *rlist;
		*rlist = elem;
	}
	return (elem ? 0 : -1);
}

void	rlist_delete(t_rows *rlist)
{
	t_rows	*next;

	while (rlist)
	{
		free(rlist->row);
		next = rlist->next;
		free(rlist);
		rlist = next;
	}
}
