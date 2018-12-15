/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:00:18 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/24 14:27:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		sign;
	int		n;

	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		++str;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '+') ? (1) : (-1);
		++str;
	}
	n = 0;
	while ('0' <= *str && *str <= '9')
	{
		n = n * 10 + sign * (int)(*str - '0');
		++str;
	}
	return (n);
}
