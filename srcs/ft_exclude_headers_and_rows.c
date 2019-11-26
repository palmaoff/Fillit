//
// Created by Louvenia Oram on 14/11/2019.
//

#include "fillit.h"

void			ft_exclude_headers_and_rows(t_cell *tetr)
{
	t_cell	*cell;
	t_cell	*temp;
	int 	i;

	i = 0;
	//Скорее всего, след строчка лишняя, т.к. *tetr - указатель на первую ячейку
	cell = ft_find_first_cell(tetr);
	while (i < 4)
	{
		temp = ft_get_hd_up(cell);
		temp = temp->d;
		while (temp)
		{
			if (temp != cell)
				ft_exclude_row(temp);
			temp = temp->d;
		}
		ft_exclude_header(cell);
		cell = cell->r;
		i++;
	}
	temp = ft_get_hd_up(tetr);
	ft_exclude_pos_block(temp, tetr);
}
