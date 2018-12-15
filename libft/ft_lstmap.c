/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:01:25 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/29 14:38:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	if ((new_lst = f(lst)) == NULL)
		return (NULL);
	new = new_lst;
	lst = lst->next;
	while (lst)
	{
		if ((new->next = f(lst)) == NULL)
		{
			ft_lstdel(&new_lst, &del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (new_lst);
}
