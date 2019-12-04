/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:06:27 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:06:34 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		ft_sqrt(int nbr)
{
	int		res;

	res = 2;
	while (res * res < nbr)
		res++;
	return (res);
}

int				dim_make(int k, t_cell *cell)
{
	t_cell	*tmp;
	int		max;

	tmp = cell;
	max = 0;
	while (tmp != NULL)
	{
		if (tmp->h > max)
			max = tmp->h;
		if (tmp->w > max)
			max = tmp->w;
		tmp = tmp->r;
	}
	k = ft_sqrt(k * 4);
	return (k > max) ? k : max;
}
