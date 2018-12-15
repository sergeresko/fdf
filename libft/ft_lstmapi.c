/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:31:35 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/29 14:39:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

t_list		*ft_lstmapi(t_list *lst, t_list *(*f)(unsigned int i, t_list *elem))
{
	t_list			*new_lst;
	t_list			*new;
	unsigned int	i;

	if (lst == NULL)
		return (NULL);
	i = 0;
	if ((new_lst = f(i, lst)) == NULL)
		return (NULL);
	new = new_lst;
	lst = lst->next;
	++i;
	while (lst)
	{
		if ((new->next = f(i, lst)) == NULL)
		{
			ft_lstdel(&new_lst, &del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
		++i;
	}
	new->next = NULL;
	return (new_lst);
}
