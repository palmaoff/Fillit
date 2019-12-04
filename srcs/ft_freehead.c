/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freehead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:12:49 by loram             #+#    #+#             */
/*   Updated: 2019/12/03 00:13:30 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void				ft_freehead(t_cell *head)
{
	t_cell		*prev;

	while (head)
	{
		prev = head;
		head = head->l;
		ft_freecell(prev);
		free(prev);
	}
}
