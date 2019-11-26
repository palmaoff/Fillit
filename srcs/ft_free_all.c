//
// Created by Louvenia Oram on 21/11/2019.
//

#include "fillit.h"

void			ft_free_all(t_cell **map, int size)
{
	int			i;
	t_cell		*tmp_cell;

	i = size;
	while (i > 0)
	{
		if (map[i]->col)
		{
			tmp_cell = map[i]->col;
			while (tmp_cell != map[i])
			{
				ft_freecell(tmp_cell);
				free(tmp_cell);
			}
		}
		i--;
	}
	ft_freehead(map[size]);
	}
