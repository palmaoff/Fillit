//
// Created by Vasya on 13.11.2019.
//

#include "fillit.h"

void			ft_include_header(t_cell *cell)
{
	t_cell	*temp;

	temp = ft_get_hd_up(cell);
	if (!temp->l)
	{
		temp->l->r = temp;
		temp->r->l = temp;
	}
	temp->inc = 1;
}
