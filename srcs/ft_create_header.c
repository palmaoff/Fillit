/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:44:16 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:01:13 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
**headarr brgins from empty list, headarr[1] is cell (0, 0)
**headarr->w - 1 - no rows in head if move ->d
*/

static void				*ft_fail_head_on_create(t_cell **headarr, int i)
{
	while (i-- >= 0)
		ft_freehead(headarr[i]);
	free(headarr);
	return (NULL);
}

static void				add_headarr_params(t_cell **headarr, int size)
{
	int			i;

	i = 1;
	while (i < (size + 1))
	{
		headarr[i - 1]->r = headarr[i];
		headarr[i]->l = headarr[i - 1];
		headarr[i]->inc = 1;
		headarr[i]->w = 1;
		i++;
	}
}

static t_cell			*ft_create_head_0(int inc, int x, int y)
{
	t_cell		*new;

	if ((new = (t_cell *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->pos = 0;
	new->w = 0;
	new->h = 0;
	new->x = x;
	new->y = y;
	new->inc = inc;
	new->l = NULL;
	new->r = NULL;
	new->d = NULL;
	new->col = NULL;
	return (new);
}

t_cell					**ft_create_header(int dim)
{
	int			y;
	int			x;
	int			k;
	t_cell		**headarr;

	if (!(headarr = (t_cell **)malloc((dim * dim + 1) * sizeof(t_cell *))))
		return (NULL);
	if (!(headarr[0] = ft_create_head_0(2, 0, 0)))
		return (ft_fail_head_on_create(headarr, 0));
	y = 0;
	k = 1;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			if (!(headarr[k++] = ft_cellnew(0, 0, x, y)))
				return (ft_fail_head_on_create(headarr, k - 1));
			x++;
		}
		y++;
	}
	add_headarr_params(headarr, dim * dim);
	return (headarr);
}
