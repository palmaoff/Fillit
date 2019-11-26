//
// Created by Louvenia Oram on 14/11/2019.
//

#include "fillit.h"

void			ft_include_pos_block(t_cell *head, int pos)
{
		t_cell	*temp_head;
		t_cell	*temp;

		temp_head = head;
		while (temp_head)
		{
			if (temp_head->col)
				ft_include_head_rows_pos(temp_head, pos);
			temp_head = temp_head->r;
		}
}
