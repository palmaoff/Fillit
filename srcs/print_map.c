//
// Created by Louvenia Oram on 22/11/2019.
//

#include "../includes/fillit.h"

void                print_map(t_cell **map, int dim)
{
	int            i;
	t_cell      *tmp;
	t_cell      *tmpt;
	int            size;
	size = dim * dim;
	i = 0;
	printf("\nmap:\n\n");
	while (i < size + 1)
	{
		printf("%d\tx: %d y: %d inc: %d W: %d \n", i, map[i]->x, map[i]->y, map[i]->inc, map[i]->w);
		tmp = map[i]->d;
		while (tmp != NULL)
		{
			printf("->\tpos: %d x: %hhu y: %hhu h: %d w: %d \n", tmp->pos,
				   tmp->x, tmp->y, tmp->h, tmp->w);
			tmp = tmp->d;
		}
		i++;
	}
}
