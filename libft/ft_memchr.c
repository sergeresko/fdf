/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:51:13 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:33:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cast_s;
	unsigned char		cast_c;

	cast_s = (const unsigned char *)s;
	cast_c = (unsigned char)c;
	while (n--)
	{
		if (*cast_s == cast_c)
			return ((void *)cast_s);
		++cast_s;
	}
	return (NULL);
}
