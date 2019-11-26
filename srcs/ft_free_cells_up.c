//
// Created by Louvenia Oram on 21/11/2019.
//


#include "fillit.h"

void			ft_free_cells_up(t_cell *head, t_cell *cell)
{
	t_cell		*temp;

	while (cell != head)
	{
		temp = cell;
		cell = cell->col;
		ft_freecell(temp);
		free(temp);
	}
	head->col = NULL;
}
