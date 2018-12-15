/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:04:35 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 19:21:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strrevdup(char const *src)
{
	char	*new;
	int		len;
	int		i;

	len = (int)ft_strlen(src);
	new = (char *)malloc(len + 1);
	if (new)
	{
		i = 0;
		while (i < len)
		{
			new[i] = src[len - 1 - i];
			++i;
		}
		new[i] = '\0';
	}
	return (new);
}

char		*ft_itoa(int n)
{
	char		rev[12];
	int			i;
	long int	abs_n;

	i = 0;
	if (n == 0)
		rev[i++] = '0';
	abs_n = (n < 0) ? -(long int)n : (long int)n;
	while (abs_n)
	{
		rev[i++] = '0' + (char)(abs_n % 10);
		abs_n /= 10;
	}
	if (n < 0)
		rev[i++] = '-';
	rev[i] = '\0';
	return (ft_strrevdup(rev));
}
