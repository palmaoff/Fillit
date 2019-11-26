#include "../includes/fillit.h"

void				ft_tetadd(t_cell *map, t_cell *new)
{
	if (map == NULL)
		map = ft_cellnew(0, 0, 0, 0);
	else
	{
		while (map->r != NULL)
			map = map->r;
		map->r = new;
	}
}
