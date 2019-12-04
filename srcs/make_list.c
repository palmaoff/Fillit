/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:27:57 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 16:27:59 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_cell		*index_cell(t_cell *list)
{
	int			i;
	t_cell		*tmp;

	tmp = list;
	i = 4;
	while (tmp != NULL)
	{
		tmp->pos = i / 4;
		tmp = tmp->r;
		i++;
	}
	return (list);
}

static t_cell		*new_item(char tetrimino[4][5], t_cell *list, int i)
{
	t_cell		*new;
	t_cell		*tmp;
	int			j;

	one_side(tetrimino);
	new = four_cells(tetrimino);
	tmp = new;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				tmp->x = j;
				tmp->y = i;
				tmp = tmp->r;
			}
			j++;
		}
		i++;
	}
	list = new_add(new, list);
	return (list);
}

t_cell				*make_list(int fd)
{
	char		*line;
	int			i;
	char		tetrimino[4][5];
	t_cell		*list;

	i = 1;
	list = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (i % 5 != 0)
			ft_strcpy(tetrimino[i % 5 - 1], line);
		if (i % 5 == 0)
			list = new_item(tetrimino, list, 0);
		i++;
		free(line);
	}
	free(line);
	list = new_item(tetrimino, list, 0);
	list = index_cell(list);
	close(fd);
	return (list);
}

static int			neighborhood(char **t, int i, int j)
{
	int			count;

	count = 0;
	if (i > 0 && t[i - 1][j] == '#')
		count++;
	if (j > 0 && t[i][j - 1] == '#')
		count++;
	if (i < 3 && t[i + 1][j] == '#')
		count++;
	if (j < 3 && t[i][j + 1] == '#')
		count++;
	return (count);
}

int					check_matrix(char **a)
{
	int			i;
	int			j;
	int			sum;
	int			count;

	j = 0;
	i = 0;
	sum = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i][j] == '#')
			{
				sum += neighborhood(a, i, j);
				count++;
			}
			j++;
		}
		i++;
	}
	return (sum < 6 || count != 4) ? 0 : 1;
}
