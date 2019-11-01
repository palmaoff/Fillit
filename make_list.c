/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   male_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:35:27 by eflorean          #+#    #+#             */
/*   Updated: 2019/10/24 13:35:30 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	make_list(int fd)
{
	char *line;
	int i;
	char	tetrisine[4][5];
	t_tetr *list;

	i = 1;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (i % 5 != 0)
			ft_strcpy(tetrisine[i % 5 - 1], line);
		if (i % 5 == 0)
			list = new_item(tetrisine);
		i++;
		free(line);
	}
	list = new_item(tetrisine);
	printf("%lli\n", list->t);
}

void one_side(char	*tetrisine[4][5])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(*tetrisine[i], '#'))
			shift_tetr(tetrisine, i, 0);
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while(i < 4)
		{
			if (*tetrisine[i][j] == '#')
				shift_tetr(tetrisine, 0, j);
			i++;
		}
		j++;
	} 
}

void	shift_tetr(char	*tetrimino[4][5], int i_sh, int j_sh)
{
	int i;
	int j;
	
	if (i_sh == 0 && j_sh == 0)
		return ;
	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*tetrimino[i][j] == '#')
			{
				*tetrimino[i][j] = '.';
				*tetrimino[i - i_sh][j - j_sh] = '#';
			}
		}
	}
}

t_tetr *new_item(char	tetrisine[4][5])
{
	t_tetr *new;
	int i;
	int j;

	i = 3;
	one_side(&tetrisine);
	new = (t_tetr *)malloc(sizeof(t_tetr));
	new->t = 0;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (tetrisine[i][j] == '#')
				new->t++;
			new->t <<= 1;
			j--;
		}
		i--;
	}
	return (new);
}