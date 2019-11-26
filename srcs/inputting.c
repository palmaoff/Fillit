/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:31:37 by eflorean          #+#    #+#             */
/*   Updated: 2019/11/20 00:29:28 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int		ft_cellin(t_cell *tmp, t_cell *cell, int pos)
{
	while (tmp->d != NULL)
		tmp = tmp->d;
	tmp->d = ft_cellnew(cell->w, cell->h, cell->x, cell->y);
	tmp->d->inc = 1;
	tmp->d->pos = pos;
	tmp->d->u = tmp;
	tmp->d->col = tmp;
	return (1);
}

void			inputting(t_cell **map, t_cell *cell, int dim)
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
			ft_cellin(tmp, cell, pos);
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

int				check_gap(t_cell *cell, int i, int dim)
{
	t_cell	*tmp;
	int		b;

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

int				inc_cell(t_cell *cell, int i, int dim)
{
	t_cell	*tmp;
	int		b;

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

void			end_head(t_cell **map, int dim)
{
	t_cell		*tmp;
	int			size;
	int			i;

	i = 1;
	size = dim * dim;
	while (i <= size)
	{
		tmp = map[i]->d;
		while (tmp && tmp->d != NULL)
			tmp = tmp->d;
		map[i]->u = tmp;
		map[i]->col = tmp;
		i++;
	}
}

static t_cell	*ft_clone(t_cell *cell, t_cell **start)
{
	t_cell *tmp;
	t_cell *new;

	tmp = cell->r;
	if (!(*start = ft_cellnew(cell->w, cell->h, cell->x, cell->y)))
		return (NULL);
	(*start)->pos = cell->pos;
	new = *start;
	while (tmp != NULL)
	{
		new->r = ft_cellnew(tmp->w, tmp->h, tmp->x, tmp->y);
		new->r->pos = tmp->pos;
		tmp = tmp->r;
		new = new->r;
	}
	return (*start);
}

void			input(t_cell **map, t_cell *cell, int dim, int k)
{
	int		b;
	t_cell	*tmp;
	int		i;
	t_cell	*start;

	i = 1;
	tmp = ft_clone(cell, &start);
	while (i <= k)
	{
		b = 1;
		while (tmp != NULL)
		{
			if (tmp->pos == i)
				break ;
			tmp = tmp->r;
		}
		while (b && tmp != NULL)
		{
			inputting(map, tmp, dim);
			b = inc_cell(tmp, i, dim);
		}
		i++;
	}
	end_head(map, dim);
	ft_freelist(start);
}
