/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:01:36 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 13:36:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *cast_s1;
	const unsigned char *cast_s2;

	cast_s1 = (const unsigned char *)s1;
	cast_s2 = (const unsigned char *)s2;
	while (n && *cast_s1 == *cast_s2)
	{
		--n;
		++cast_s1;
		++cast_s2;
	}
	if (n)
		return ((int)*cast_s1 - (int)*cast_s2);
	return (0);
}
