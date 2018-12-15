/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:06:04 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:22:33 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cast_c;
	unsigned char	*cast_b;

	cast_b = (unsigned char *)b;
	cast_c = (unsigned char)c;
	while (len--)
		*(cast_b++) = cast_c;
	return (b);
}
