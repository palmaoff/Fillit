//
// Created by Dmitry Badeev on 23/11/2019.
//

#include "fillit.h"

int 				ft_check_heads_tetr_w(t_cell *cell)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;
	int 		i;

	temp_cell = ft_find_first_cell(cell);
	i = 0;
	while (i < 4)
	{
		temp_head = ft_get_hd_up(temp_cell);
		if (temp_head->w == 1)
			return (1);
		temp_cell = temp_cell->r;
		i++;
	}
	return (0);
}
