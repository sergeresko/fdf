/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:35:05 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/27 12:22:55 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*dst;

	if ((new = (char *)malloc(len + 1)))
	{
		dst = new;
		s += start;
		while (len--)
			*(dst++) = *(s++);
		*dst = '\0';
	}
	return (new);
}
