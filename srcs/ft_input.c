/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:00:54 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 16:00:56 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void			end_head(t_cell **map, int dim)
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
		map[i]->col = tmp;
		i++;
	}
}

static t_cell		*ft_clone(t_cell *cell, t_cell **start)
{
	t_cell		*tmp;
	t_cell		*new;

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

void				input(t_cell **map, t_cell *cell, int dim, int k)
{
	int			b;
	t_cell		*tmp;
	int			i;
	t_cell		*start;

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
