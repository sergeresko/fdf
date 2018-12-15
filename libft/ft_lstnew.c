/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:36:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/27 13:13:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		if (content == NULL || content_size == 0)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else if ((new->content = malloc(content_size)))
		{
			(void)ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		else
		{
			free(new);
			return (NULL);
		}
		new->next = NULL;
	}
	return (new);
}
