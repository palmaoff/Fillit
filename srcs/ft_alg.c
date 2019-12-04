/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:09:31 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/03 03:32:34 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void			heads_tetr_inc_sw(t_cell *cell, int sw)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;

	temp_cell = ft_find_first_cell(cell);
	while (temp_cell)
	{
		temp_head = ft_get_hd_up(temp_cell);
		temp_head->inc = sw;
		temp_cell = temp_cell->r;
	}
}

static void			ft_include_head_rows_inc(t_cell *head, int pos_num)
{
	t_cell	*temp_h;
	t_cell	*temp_u;

	temp_h = head->r;
	while (temp_h)
	{
		temp_u = temp_h->col;
		while (temp_u && (temp_u != temp_h))
		{
			if ((temp_u->inc == pos_num) || (temp_u->inc == pos_num - 50))
				ft_include_row(temp_u);
			temp_u = temp_u->col;
		}
		if (temp_h->col)
			temp_h->w = 1;
		temp_h = temp_h->r;
	}
}

int					ft_alg(t_cell *head, int pos_num, int pos, t_cell **map)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;

	temp_head = head->r;
	while (temp_head)
	{
		temp_cell = temp_head->d;
		while ((temp_cell != NULL) && (temp_cell->pos == pos_num))
		{
			ft_excl_all_h_and_r(map[0], temp_cell, pos_num);
			if (pos_num == pos)
				return (1);
			if (ft_alg(map[0], pos_num + 1, pos, map))
				return (1);
			heads_tetr_inc_sw(temp_cell, 1);
			ft_inc_all_h_and_r(map[0], temp_cell, pos_num);
			ft_exclude_row(temp_cell, pos_num + 100);
			temp_cell = temp_cell->d;
		}
		temp_head->w = 0;
		temp_head = temp_head->r;
	}
	ft_include_head_rows_inc(map[0], pos_num + 100);
	return (0);
}
