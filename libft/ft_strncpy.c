/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:39:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 16:38:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*orig_dst;

	orig_dst = dst;
	while (len)
	{
		--len;
		if ((*(dst++) = *(src++)) == '\0')
			break ;
	}
	while (len--)
		*(dst++) = '\0';
	return (orig_dst);
}
