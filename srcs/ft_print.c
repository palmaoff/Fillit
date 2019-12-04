/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:17:45 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:17:50 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void				ft_freearea(char **area, int dim)
{
	dim--;
	while (dim >= 0)
	{
		free(*(area + dim));
		dim--;
	}
	free(area);
}

static char			**ft_area(int dim)
{
	int		i;
	char	**area;

	i = 0;
	area = (char **)malloc(dim * sizeof(char *));
	while (i < dim)
	{
		*(area + i) = (char *)malloc((dim + 1) * sizeof(char));
		*(*(area + i) + dim) = '\0';
		ft_memset(area[i], '.', dim);
		i++;
	}
	return (area);
}

void				ft_print(t_cell **map, int dim)
{
	char	**area;
	t_cell	*tmp;
	int		i;

	area = ft_area(dim);
	i = 1;
	while (i <= dim * dim)
	{
		tmp = map[i]->d;
		if (tmp != NULL)
			*(*(area + tmp->y) + tmp->x) = (char)(64 + tmp->pos);
		i++;
	}
	i = 0;
	while (i < dim)
	{
		ft_putstr(*(area + i));
		ft_putchar('\n');
		i++;
	}
	ft_freearea(area, dim);
}
