//
// Created by Vasya on 13.11.2019.
//
/*
 * head->inc - флаг выключенности (занятости) ячейки карты (хедера)
 */
#include "fillit.h"

void			ft_exclude_header(t_cell *cell)
{
	t_cell	*temp;

	temp = ft_get_hd_up(cell);
	if (temp->l)
	{
		temp->l->r = temp->r;
		if (temp->r)
			temp->r->l = temp->l;
	}
	temp->inc = 0;
}
