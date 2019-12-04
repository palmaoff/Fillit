/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclude_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:06:32 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:06:37 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_exclude_row(t_cell *tetr, int inc)
{
	t_cell	*temp_cell;
	t_cell	*temp;
	int		i;

	temp_cell = ft_find_first_cell(tetr);
	i = 0;
	while (i < 4)
	{
		temp = temp_cell->col;
		while ((temp->inc < 254) && (temp->h != 0))
			temp = temp->col;
		temp->d = temp_cell->d;
		temp_cell->inc = inc;
		temp_cell = temp_cell->r;
		i++;
	}
}
