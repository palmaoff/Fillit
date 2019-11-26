//
// Created by Vasya on 13.11.2019.
//

#include "fillit.h"

void			ft_include_head_rows_pos(t_cell *head, int pos)
{
	t_cell	*temp_u;

	temp_u = head->col;
	while ((temp_u != head) && (temp_u->pos != pos))
		temp_u = temp_u->col;
	if (temp_u != head)
		while (temp_u->pos == pos)
		{
			if (!(temp_u->inc) && (!ft_check_heads_tetr_w(temp_u)))
					ft_include_row(temp_u);
			temp_u = temp_u->col;
		}
}
