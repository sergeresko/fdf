/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:31:27 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/26 16:35:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*dst;

	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if ((dst = new))
	{
		while ((*(dst++) = *(s1++)))
			;
		--dst;
		while ((*(dst++) = *(s2++)))
			;
	}
	return (new);
}
