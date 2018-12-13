#include <stdlib.h>
#include "my_fdf.h"

/*
**	Adds a new element to the beginning of the list.
**	Returns 0 on success and -1 if memory couldn't be allocated.
**	TODO: Make the function void and remove checks.
*/

int		list_push(t_int_list **list, int *array)
{
	t_int_list	*elem;

	elem = (t_int_list *)malloc(sizeof(t_int_list));
	if (elem)
	{
		elem->array = array;
		elem->next = *list;
		*list = elem;
	}
	return (elem ? 0 : -1);
}

void	list_delete(t_int_list *list)
{
	t_int_list	*next;

	while (list)
	{
		free(list->array);
		next = list->next;
		free(list);
		list = next;
	}
}
