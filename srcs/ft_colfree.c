//
// Created by Louvenia Oram on 12/11/2019.
//

#include "../includes/fillit.h"


void		ft_colfree(t_cell *head)
{
	t_cell		*point;
	t_cell		*prev;

	point = head->col;
	if (point)
		while (point != head)
		{
			prev = point->col;
			ft_freecell(point);
			free(point);
			point = prev;
		}
}
