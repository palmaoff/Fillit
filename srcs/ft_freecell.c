/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:10:04 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:10:14 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_freecell(t_cell *cell)
{
	cell->pos = 0;
	cell->w = 0;
	cell->h = 0;
	cell->x = 0;
	cell->y = 0;
	cell->inc = 0;
	cell->l = NULL;
	cell->r = NULL;
	cell->d = NULL;
	cell->col = NULL;
}
