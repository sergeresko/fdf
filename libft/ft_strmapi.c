/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:18:07 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 15:55:49 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*dst;
	unsigned int	i;

	new = (char *)malloc(ft_strlen(s) + 1);
	if ((dst = new))
	{
		i = 0;
		while (*s)
			*(dst++) = f(i++, *(s++));
		*dst = '\0';
	}
	return (new);
}
