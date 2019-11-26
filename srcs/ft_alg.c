//
// Created by Louvenia Oram on 14/11/2019.
//
/**
 * head->w - в столбце есть начало тетраминки на выход
 * head->inc - датчик включенности столбца. 1 - включен, 0 - выключен
 * ft_alg возвращает 1, если найдены все pos, 0 - нужно увеличивать карту
 **/
#include "fillit.h"

static void			heads_tetr_w_sw(t_cell *cell, int sw)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;
	int 		i;

	temp_cell = ft_find_first_cell(cell);
	i = 0;
	while (i < 4)
	{
		temp_head = ft_get_hd_up(temp_cell);
		temp_head->w = sw;
		temp_cell = temp_cell->r;
		i++;
	}
}


int					ft_alg(t_cell *head, int pos_num, int pos, t_cell **map)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;

	temp_head = head->r;
//	head->h = 0;
	while (temp_head)
	{
		temp_cell = temp_head->d;
		while (temp_cell)
		{
//			head->inc = 0;
//			head->w = 1;
//			не забыть переставить обратно
			ft_exclude_all_headers_and_rows(map[0], temp_cell);
			heads_tetr_w_sw(temp_cell, 1);
			if ((pos_num + 1) == pos)
				return (1);
			printf("On board: %d, Last pos: %d\n", pos_num + 1, temp_cell->pos);
			print_map(map, 4);
			if (ft_alg(map[0], ++pos_num, pos, map))
				return (1);
			heads_tetr_w_sw(temp_cell, 0);
			ft_include_all_headers_and_rows(map[0], temp_head, temp_cell);
			pos_num--;
			ft_exclude_row(temp_cell);
			printf("Rejected: %d, Last pos: %d\n", pos_num - 1, temp_cell->pos);
			printf("After INCLUDE:\n");
			print_map(map, 4);
//			head->w = 0;
//			head->inc = 1;
			temp_cell = temp_cell->d;
		}
		temp_head = temp_head->r;
	}
	return (0);
}
