/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inc_all_h_and_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:17:31 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:17:53 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void			ft_include_head_rows_pos(t_cell *head, int pos)
{
	t_cell	*temp_u;

	temp_u = head->col;
	while ((temp_u != head) && (temp_u->pos != pos))
		temp_u = temp_u->col;
	if (temp_u != head)
		while (temp_u->pos == pos)
		{
			if ((temp_u->inc < 100) && (!ft_check_heads_tetr_inc(temp_u)))
			{
				ft_include_row(temp_u);
			}
			temp_u = temp_u->col;
		}
}

static void			ft_include_pos_block(t_cell *head, int pos)
{
	t_cell	*temp_head;

	temp_head = head;
	while (temp_head)
	{
		if (temp_head->col)
			ft_include_head_rows_pos(temp_head, pos);
		temp_head = temp_head->r;
	}
}

static void			ft_include_header(t_cell *cell)
{
	t_cell	*temp;
	t_cell	*temp_h;

	temp_h = ft_get_hd_up(cell);
	temp = temp_h->l;
	while (!(temp->inc))
		temp = temp->l;
	temp_h->r = temp->r;
	temp->r = temp_h;
	temp->inc = 1;
}

void				ft_inc_all_h_and_r(t_cell *head0, t_cell *tetr, int pos_num)
{
	t_cell	*cell;
	t_cell	*temp;
	t_cell	*temp_h;
	int		i;

	cell = ft_find_first_cell(tetr);
	ft_include_pos_block(head0, tetr->pos);
	i = 0;
	while (i < 4)
	{
		temp_h = ft_get_hd_up(cell);
		ft_include_header(temp_h);
		temp = temp_h->col;
		while (temp &&
			(((temp != cell) && !(cell->l)) || ((temp != temp_h) && cell->l)))
		{
			temp_h = ft_get_hd_up(temp);
			if ((temp->inc == pos_num + 50) && temp_h->inc)
				ft_include_row(temp);
			temp = temp->col;
		}
		cell = cell->r;
		i++;
	}
}
