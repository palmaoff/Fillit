/*
** Seek head for cell with the same coordinates x and y
 */
#include "../includes/fillit.h"

t_cell		*ft_get_hd_xy(t_cell *cell, t_cell **head, int size)
{
	int 	i;

	i = 0;
	while (i < size)
	{
		if ((cell->x == head[i]->x) && (cell->y == head[i]->y))
			return (&*head[i]);
		else
			i++;
	}
	return (NULL);
}
