//
// Created by Louvenia Oram on 12/11/2019.
//

#include "../includes/fillit.h"

void				ft_freehead(t_cell *head)
{
	t_cell		*prev;

	while (head)
	{
		prev = head->l;
		ft_freecell(head);
		head = prev;
		free(prev->r);
	}
}

