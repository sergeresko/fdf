/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:30:30 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:48:20 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;

	cast_c = (char)c;
	while (*s)
	{
		if (*s == cast_c)
			return ((char *)s);
		++s;
	}
	if (cast_c == '\0')
		return ((char *)s);
	return (NULL);
}
