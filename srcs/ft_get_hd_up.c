/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hd_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:14:58 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:15:05 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cell			*ft_get_hd_up(t_cell *cell)
{
	t_cell	*temp_cell;

	temp_cell = cell;
	while (temp_cell->h != 0)
		temp_cell = temp_cell->col;
	return (temp_cell);
}
