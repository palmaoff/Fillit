//
// Created by Louvenia Oram on 14/11/2019.
//
/**
 * Если тетраминка включена в pos на предыдущих шагах, то мы не можем попасть в
 * header's, где есть активные ячейки этой тетраминки, т.к. headers были
 * выключены.
 * 27-28 - !!!сама ячейка (и тетраминка) не выключается!!!
 */
#include "fillit.h"

void			ft_exclude_all_headers_and_rows(t_cell *head0, t_cell *tetr)
{
	t_cell	*cell;
	t_cell	*temp;
	int		i;

	i = 0;
	//Скорее всего, след строчка лишняя, т.к. *tetr - указатель на первую ячейку
	cell = ft_find_first_cell(tetr);
	while (i < 4)
	{
		temp = ft_get_hd_up(cell);
		temp = temp->d;
		while (temp)
		{
			if ((ft_find_first_cell(temp) != tetr) && !(ft_check_heads_tetr_w
			(temp)))
				ft_exclude_row(temp);
			temp = temp->d;
		}
		ft_exclude_header(cell);
		cell = cell->r;
		i++;
	}
	ft_exclude_pos_block(head0, tetr);
}
