/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:49:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/16 17:44:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
//#include <unistd.h>
//#include <fcntl.h>
#include "libft.h"

static int	word_count(char **tab)
{
	int		count;

	count = 0;
	while (*(tab++))
		++count;
	return (count);
}

static void	free_str_array(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

/*
**	Reads a line from fd and converts it into an array of integers.
**	Arguments:
**		fd		--	file descriptor
**		array	--	address of a variable where the pointer to the allocated
**					array of integers is to be stored
**		width	--	address of a variable where the (int) width is to be stored
**	Return value:
**		-1		--	if get_next_line returned -1
**				--	if ft_strsplit couldn't allocate memory
**				--	if there are no words in the line
**				--	if memory couldn't be allocated for *array
**		0		--	on success
**	*array is NULL if the return value is -1 or if get_next_line returned 0.
**	*width makes sense only if the return value is 0 and *array is not NULL.
*/

static int	fdf_parse_line(int fd, int **array, int *width)
{
	char	*line;
	char	**tab;
	int		ret;
	int		x;

	*array = NULL;
	ret = get_next_line(fd, &line);
	if (ret < 1)
		return (ret);
	tab = ft_strsplit(line, ' ');
	free(line);
	if (tab == NULL)
		return (-1);
	*width = word_count(tab);
	if (*width)
	{
		*array = (int *)malloc(*width * sizeof(int));
		if (*array)
		{
			x = 0;
			while (x < *width)
			{
				(*array)[x] = ft_atoi(tab[x]);
				++x;
			}
		}
	}
	free_str_array(tab);
	return (*array ? 0 : -1);
}

/*
**	Allocates a list whose elements contain arrays of values in reverse order.
**	Arguments:
**		fd		--	file descriptor
**		list	--	address of a variable to store the pointer to the list's
**					first element
**		width	--	address of a variable to store the width
**		height	--	address of a variable to store the height
**	Return value:
**		-1		--	if fdf_parse_line didn't return 1 for the first line
**				--	if fdf_parse_line returned -1 for any subsequent line
**				--	if lines have different number of values
**		0		--	on success
**	*width and *height make sense only if the return value is 0.
*/

static int	fdf_parse_into_list(int fd, t_rows **rlist, int *width, int *height)
{
	int		*row;
	int		width_curr;

	*rlist = NULL;
	*height = 0;
	if (fdf_parse_line(fd, &row, width) < 0)
		return (-1);
//	if (*width == 0)
//	{
//		free(array);
//		return (-1);
//	}
	rlist_push(rlist, row);
	++(*height);
/*
	if (list_push(list, array) < 0)		//
	{									//	replaced this with the previous line
		free(array);					//
		return (-1);					//	don't check if there's enough memory
	}									//
*/
	while (1)
	{
		if (fdf_parse_line(fd, &row, &width_curr) < 0 || width_curr != *width)
			/* || (array && list_push(list, array) < 0) */
			// remove this line
		{
			free(row);
			rlist_delete(*rlist);
			return (-1);
		}
		if (row == NULL)
			return (0);
		rlist_push(rlist, row);		// don't check if there's enough memory
		++(*height);
	}
}

t_fdf		*fdf_parse(int fd)
{
	t_fdf	*fdf;
	t_rows	*rlist;
	t_rows	*next;
	int		y;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf_parse_into_list(fd, &rlist, &(fdf->width), &(fdf->height)) < 0)
	{
		free(fdf);
		return (NULL);
	}
	fdf->values = (int **)malloc(fdf->height * sizeof(int *));
	y = fdf->height;
	while (y--)
	{
		fdf->values[y] = rlist->row;
		next = rlist->next;
		free(rlist);
		rlist = next;
	}
	return (fdf);
}
