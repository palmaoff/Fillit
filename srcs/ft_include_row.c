//
// Created by Louvenia Oram on 14/11/2019.
//

#include "fillit.h"

void			ft_include_row(t_cell *tetr)
{
	int 	i;
	t_cell	*temp_cell;

	i = 0;
	temp_cell = ft_find_first_cell(tetr);
	while (i < 4)
	{
		if (temp_cell->d)
			temp_cell->d->u = temp_cell;
		temp_cell->u->d = temp_cell;
		temp_cell->inc = 1;
		temp_cell = temp_cell->r;
		i++;
	}
}
