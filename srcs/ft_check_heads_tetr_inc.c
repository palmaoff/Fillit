/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_heads_tetr_inc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:41:46 by loram             #+#    #+#             */
/*   Updated: 2019/12/02 23:41:56 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int					ft_check_heads_tetr_inc(t_cell *cell)
{
	t_cell		*temp_head;
	t_cell		*temp_cell;

	temp_cell = ft_find_first_cell(cell);
	while (temp_cell)
	{
		temp_head = ft_get_hd_up(temp_cell);
		if (temp_head->inc == 0)
			return (1);
		temp_cell = temp_cell->r;
	}
	return (0);
}
