/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cellnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:11:00 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:11:08 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cell				*ft_cellnew(int w, int h, int x,
								int y)
{
	t_cell		*new;

	if ((new = (t_cell *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->pos = 0;
	new->w = w;
	new->h = h;
	new->x = x;
	new->y = y;
	new->inc = 0;
	new->l = NULL;
	new->r = NULL;
	new->d = NULL;
	new->col = NULL;
	return (new);
}
