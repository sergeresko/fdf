#include <stdlib.h>
#include "my_fdf.h"

/*
**	Adds a new element to the beginning of the list.
**	Returns 0 on success and -1 if memory couldn't be allocated.
**	TODO: Make the function void and remove checks.
*/

int		list_push(t_rows **list, int *row)
{
	t_rows	*elem;

	elem = (t_rows *)malloc(sizeof(t_rows));
	if (elem)
	{
		elem->row = row;
		elem->next = *list;
		*list = elem;
	}
	return (elem ? 0 : -1);
}

void	list_delete(t_rows *list)
{
	t_rows	*next;

	while (list)
	{
		free(list->row);
		next = list->next;
		free(list);
		list = next;
	}
}
