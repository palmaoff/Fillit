/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:19:29 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:19:41 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** inc = 254, if re-include, first value = 255
*/

void			ft_include_row(t_cell *tetr)
{
	t_cell	*temp_cell;
	t_cell	*temp;
	int		i;

	temp_cell = ft_find_first_cell(tetr);
	i = 0;
	while (i < 4)
	{
		temp = temp_cell;
		while ((temp->inc < 254) && (temp->h != 0))
			temp = temp->col;
		temp_cell->d = temp->d;
		temp->d = temp_cell;
		temp_cell->inc = 254;
		temp_cell = temp_cell->r;
		i++;
	}
}
