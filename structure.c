/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:49:31 by eflorean          #+#    #+#             */
/*   Updated: 2019/11/08 14:49:35 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	massive()
{
	static int i;
}

void	h_and_w(t_tetr *list, char tetrimino[4][5])
{
	static int i;
	int j;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(tetrimino[i], '#'))
			list->h = i + 1;
		i++;
	}
	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetrimino[i][j] == '#')
				list->w = j + 1;
			i++;
		}
		j++;
	}
}

void	fillit()
{
	
}