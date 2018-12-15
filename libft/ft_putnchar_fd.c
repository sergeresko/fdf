/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:04:20 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 20:43:22 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnchar_fd(char c, int times, int fd)
{
	char	buf[16];

	ft_memset(buf, c, 16);
	while (times > 16)
	{
		write(fd, buf, 16);
		times -= 16;
	}
	if (times > 0)
		write(fd, buf, times);
}
