/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:26:32 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/29 13:39:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiteri(t_list *lst, void (*f)(unsigned int i, t_list *elem))
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		f(i, lst);
		++i;
		lst = lst->next;
	}
}
