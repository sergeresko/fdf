/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:55:08 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:32:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;
	unsigned char	cast_c;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	cast_c = (unsigned char)c;
	while (n--)
		if ((*(cast_dst++) = *(cast_src++)) == cast_c)
			return ((void *)cast_dst);
	return (NULL);
}
