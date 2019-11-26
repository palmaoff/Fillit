//
// Created by Louvenia Oram on 14/11/2019.
//

#include "fillit.h"

void			ft_include_all_headers_and_rows(t_cell *head0, t_cell *head,
												t_cell *tetr)
{
	t_cell	*cell;
	t_cell	*temp;
	int 	i;

	i = 0;
	//Скорее всего, след строчка лишняя, т.к. *tetr - указатель на первую ячейку
	cell = ft_find_first_cell(tetr);
	ft_include_pos_block(head0, tetr->pos);
	while (i < 4)
	{
		temp = ft_get_hd_up(cell);
		ft_include_header(temp);
		temp = temp->col;
		while (temp != cell)
		{
			if (!(ft_check_heads_tetr_w(temp)) && !(temp->inc))
				ft_include_row(temp);
			temp = temp->col;
		}
		cell = cell->r;
		i++;
	}
}
