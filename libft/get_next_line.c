/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:00:10 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/09 19:33:47 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static t_flist	*find(int fd, t_flist **afiles)
{
	t_flist	*file;

	if (afiles == NULL)
		return (NULL);
	file = *afiles;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	file = (t_flist *)malloc(sizeof(t_flist));
	if (file == NULL)
		return (NULL);
	file->fd = fd;
	file->start = 0;
	file->end = 0;
	file->next = *afiles;
	*afiles = file;
	return (file);
}

/*
** Create a null-terminated string composed of the first n1 characters of s1
** followed by the first n2 characters of s2, then free s1 if it is not NULL.
** Return a pointer to the new string.
*/

static char		*ft_strnjoin(char *s1, int n1, char *s2, int n2)
{
	char	*old_s1;
	char	*new;
	char	*dst;

	old_s1 = s1;
	new = (char *)malloc(n1 + n2 + 1);
	if (new)
	{
		dst = new;
		while (n1--)
			*(dst++) = *(s1++);
		while (n2--)
			*(dst++) = *(s2++);
		*dst = '\0';
	}
	if (old_s1)
		free(old_s1);
	return (new);
}

static int		newline_index(const char *s, int len)
{
	int		i;

	i = 0;
	while (i < len && s[i] != '\n')
		++i;
	return (i);
}

static int		gnl(t_flist *f, char **line)
{
	int		eol;
	int		length;

	length = 0;
	while (1)
	{
		if (f->end <= f->start)
		{
			f->start = 0;
			f->end = read(f->fd, f->buf, GNL_BUF_SIZE);
			if (f->end == -1)
				return (-1);
			if (f->end == 0)
				return (*line != NULL);
		}
		eol = f->start + newline_index(f->buf + f->start, f->end - f->start);
		*line = ft_strnjoin(*line, length, f->buf + f->start, eol - f->start);
		if (*line == NULL)
			return (-1);
		length += eol - f->start;
		f->start = eol + 1;
		if (eol < f->end)
			return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_flist	*files = NULL;
	t_flist			*file;

	if (line == NULL)
		return (-1);
	*line = NULL;
	file = find(fd, &files);
	if (file == NULL)
		return (-1);
	return (gnl(file, line));
}
