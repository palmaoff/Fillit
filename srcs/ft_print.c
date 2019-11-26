//
// Created by Emilee Florean on 25/11/2019.
//

#include "../includes/fillit.h"

static void ft_freearea(char **area, int dim)
{
	dim--;
	while (dim >= 0)
	{
		free(*(area + dim));
		dim--;
	}
	free(area);
}

static	char	**ft_area(int dim)
{
	int i;
	char **area;

	i = 0;
	area = (char **)malloc(dim * sizeof(char *));
	while (i < dim)
	{
		*(area + i) = malloc(dim * sizeof(char) + 1);
		ft_memset(area[i], '.', dim);
		i++;
	}
	return (area);
}

void ft_print(t_cell **map, int dim)
{
	char **area;
	t_cell *tmp;
	int i;

	area = ft_area(dim);
	i = 1;
	while (i <= dim * dim)
	{
		tmp = map[i]->d;
		while (tmp != NULL)
		{
			*(*(area + tmp->x) + tmp->y) = 64 + tmp->pos;
			tmp = tmp->d;
		}
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