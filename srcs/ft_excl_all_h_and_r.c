/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excl_all_h_and_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:03:23 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:05:46 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Если тетраминка включена в pos на предыдущих шагах, то мы не можем попасть в
** header's, где есть активные ячейки этой тетраминки, т.к. headers были
** выключены.
** 27-28 - !!!сама ячейка (и тетраминка) не выключается!!!
** По столбцу выключается с inc = pos_num + 50
**  По pos выключается с inc = pos
*/

static void		ft_exclude_head_rows_pos(t_cell *head, t_cell *tetr)
{
	t_cell	*temp_d;

	temp_d = head->d;
	while (temp_d && (temp_d->pos != tetr->pos))
		temp_d = temp_d->d;
	while (temp_d && (temp_d->pos == tetr->pos))
	{
		if (temp_d != tetr)
			ft_exclude_row(temp_d, tetr->pos);
		temp_d = temp_d->d;
	}
}

static void		ft_exclude_pos_block(t_cell *head, t_cell *tetr)
{
	t_cell	*temp_head;

	temp_head = head->r;
	while (temp_head)
	{
		ft_exclude_head_rows_pos(temp_head, tetr);
		temp_head = temp_head->r;
	}
}

static void		ft_exclude_header(t_cell *cell)
{
	t_cell	*temp;
	t_cell	*temp_h;

	temp_h = ft_get_hd_up(cell);
	temp = temp_h->l;
	while (!(temp->inc))
		temp = temp->l;
	temp->r = temp_h->r;
	temp_h->inc = 0;
}

void			ft_excl_all_h_and_r(t_cell *head0, t_cell *tetr, int pos_num)
{
	t_cell	*cell;
	t_cell	*temp;
	int		i;

	cell = ft_find_first_cell(tetr);
	i = 0;
	while (i < 4)
	{
		temp = ft_get_hd_up(cell);
		temp = temp->d;
		while (temp)
		{
			if (ft_find_first_cell(temp) != tetr)
				ft_exclude_row(temp, pos_num + 50);
			temp = temp->d;
		}
		ft_exclude_header(cell);
		cell = cell->r;
		i++;
	}
	ft_exclude_pos_block(head0, tetr);
}
