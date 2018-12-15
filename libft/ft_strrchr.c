/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:17:20 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:51:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	char		cast_c;

	last = NULL;
	cast_c = (char)c;
	while (*s)
	{
		if (*s == cast_c)
			last = s;
		++s;
	}
	if (cast_c == '\0')
		return ((char *)s);
	return ((char *)last);
}
