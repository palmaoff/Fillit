//
// Created by Vasya on 13.11.2019.
//

#include "fillit.h"

t_cell			*ft_get_hd_up(t_cell *cell)
{
	t_cell	*temp_cell;

	temp_cell = cell;
	while (temp_cell->h != 0)
		temp_cell = temp_cell->col;
	return (temp_cell);
}
