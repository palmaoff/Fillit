/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:41:38 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:38:29 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int			shift_tetr(char tetrimino[4][5], int i_sh, int j_sh)
{
	int		i;
	int		j;

	if (i_sh == 0 && j_sh == 0)
		return (4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				tetrimino[i][j] = '.';
				tetrimino[i - i_sh][j - j_sh] = '#';
			}
			j++;
		}
		i++;
	}
	return (4);
}

static void			h_and_w(int *w, int *h, char tetrimino[4][5])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(tetrimino[i], '#'))
			*h = i + 1;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetrimino[i][j] == '#')
				*w = j + 1;
			i++;
		}
		j++;
	}
}

void				one_side(char tetrimino[4][5])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(tetrimino[i], '#'))
			i = shift_tetr(tetrimino, i, 0);
		i++;
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				i = shift_tetr(tetrimino, 0, j);
				j = 4;
			}
			i++;
		}
		j++;
	}
}

t_cell				*new_add(t_cell *new, t_cell *list)
{
	t_cell	*tmp;

	tmp = list;
	if (list == NULL)
		list = new;
	else
	{
		while (tmp->r != NULL)
			tmp = tmp->r;
		tmp->r = new;
	}
	return (list);
}

t_cell				*four_cells(char tetrimino[4][5])
{
	t_cell	*new;
	t_cell	*tmp;
	int		i;

	i = 0;
	new = ft_cellnew(0, 0, 0, 0);
	h_and_w(&new->w, &new->h, tetrimino);
	tmp = new;
	while (i < 3)
	{
		tmp->r = ft_cellnew(0, 0, 0, 0);
		h_and_w(&tmp->r->w, &tmp->r->h, tetrimino);
		tmp = tmp->r;
		i++;
	}
	return (new);
}
