/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:26:57 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 12:41:15 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;

	dst = s1;
	while (*dst)
		++dst;
	while (n--)
		if ((*(dst++) = *(s2++)) == '\0')
			return (s1);
	*dst = '\0';
	return (s1);
}
