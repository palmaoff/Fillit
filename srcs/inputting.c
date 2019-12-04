/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:31:37 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:16:21 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int			ft_cellin(t_cell **tmp, t_cell *cell, int pos)
{
	while ((*tmp)->d != NULL)
		(*tmp) = (*tmp)->d;
	(*tmp)->d = ft_cellnew(cell->w, cell->h, cell->x, cell->y);
	(*tmp)->d->inc = 255;
	(*tmp)->d->pos = pos;
	(*tmp)->d->col = *tmp;
	return (1);
}

void				inputting(t_cell **map, t_cell *cell, int dim)
{
	int			i;
	int			pos;
	t_cell		*tmp;
	t_cell		*last;

	last = NULL;
	pos = cell->pos;
	i = 1;
	while (i <= (dim * dim) && cell != NULL && cell->pos == pos)
	{
		if (cell->x == map[i]->x && cell->y == map[i]->y)
		{
			tmp = map[i];
			ft_cellin(&tmp, cell, pos);
			if (last != NULL)
			{
				last->r = tmp->d;
				tmp->d->l = last;
			}
			last = tmp->d;
			cell = cell->r;
		}
		i++;
	}
}

static int			check_gap(t_cell *cell, int i, int dim)
{
	t_cell		*tmp;
	int			b;

	tmp = cell;
	b = 1;
	while (tmp != NULL && tmp->pos == i)
	{
		if (tmp->x == (dim - 1))
			b = 2;
		if (tmp->y == (dim - 1) && b == 2)
			b = 0;
		tmp = tmp->r;
	}
	return (b);
}

int					inc_cell(t_cell *cell, int i, int dim)
{
	t_cell		*tmp;
	int			b;

	tmp = cell;
	b = check_gap(cell, i, dim);
	if (b == 0)
		return (0);
	while (tmp != NULL && tmp->pos == i)
	{
		if (b == 1)
			tmp->x++;
		else if (b == 2)
		{
			tmp->y++;
			tmp->x -= dim - tmp->w;
		}
		tmp = tmp->r;
	}
	return (1);
}
