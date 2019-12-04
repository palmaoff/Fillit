/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:16:54 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:17:00 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_freelist(t_cell *list)
{
	t_cell	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->r;
		free(tmp);
	}
}
