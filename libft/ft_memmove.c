/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:23:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 11:44:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cast_dst;
	const char	*cast_src;

	if (dst < src)
	{
		cast_dst = (char *)dst;
		cast_src = (const char *)src;
		while (len--)
			*(cast_dst++) = *(cast_src++);
	}
	else if (dst > src)
	{
		cast_dst = (char *)dst + len;
		cast_src = (const char *)src + len;
		while (len--)
			*(--cast_dst) = *(--cast_src);
	}
	return (dst);
}
