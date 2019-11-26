//
// Created by Louvenia Oram on 14/11/2019.
//

#include "fillit.h"

void			ft_exclude_pos_block(t_cell *head, t_cell *tetr)
{
		t_cell	*temp_head;
		t_cell	*temp;

		temp_head = head->r;
		while (temp_head)
		{
			ft_exclude_head_rows_pos(temp_head, tetr);
			temp_head = temp_head->r;
		}
}
