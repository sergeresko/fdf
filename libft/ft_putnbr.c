/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:52:47 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/24 17:22:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	if (0 <= n && n <= 9)
		ft_putchar('0' + (char)n);
	else if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(-(n % 1000000000));
		}
		else
			ft_putnbr(-n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + (char)(n % 10));
	}
}
