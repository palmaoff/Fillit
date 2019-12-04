/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_cell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:07:25 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:07:28 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cell			*ft_find_first_cell(t_cell *cell)
{
	t_cell	*head_tetr;

	head_tetr = cell;
	while (head_tetr->l)
		head_tetr = head_tetr->l;
	return (head_tetr);
}
