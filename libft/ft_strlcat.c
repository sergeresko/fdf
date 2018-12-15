/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:47:47 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 15:28:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;

	total = 0;
	while (dstsize && *dst)
	{
		--dstsize;
		++dst;
		++total;
	}
	while (dstsize > 1 && *src)
	{
		--dstsize;
		*(dst++) = *(src++);
		++total;
	}
	if (dstsize)
		*dst = '\0';
	while (*(src++))
		++total;
	return (total);
}
