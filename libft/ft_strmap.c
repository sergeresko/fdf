/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:09:58 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 15:53:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*dst;

	new = (char *)malloc(ft_strlen(s) + 1);
	if ((dst = new))
	{
		while (*s)
			*(dst++) = f(*(s++));
		*dst = '\0';
	}
	return (new);
}
