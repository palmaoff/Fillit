//
// Created by Louvenia Oram on 12/11/2019.
//

#include "../includes/fillit.h"

void				ft_freecell(t_cell *cell)
{
	cell->pos = 0;
	cell->w = 0;
	cell->h = 0;
	cell->x = 0;
	cell->y = 0;
	cell->inc = 0;
	cell->l = NULL;
	cell->r = NULL;
	cell->u = NULL;
	cell->d = NULL;
	cell->col = NULL;
}
