//
// Created by Vasya on 13.11.2019.
//
/*
 * Выключаются все тетраминки, кроме той, которая выбрана "на выход"
 */
#include "fillit.h"

void			ft_exclude_head_rows_pos(t_cell *head, t_cell *tetr)
{
	t_cell	*temp_d;

	temp_d = head->d;
	while (temp_d && (temp_d->pos != tetr->pos))
		temp_d = temp_d->d;
	while (temp_d && (temp_d->pos == tetr->pos))
	{
		if (temp_d != tetr)
			ft_exclude_row(temp_d);
		temp_d = temp_d->d;
	}
}
