/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:41:38 by eflorean          #+#    #+#             */
/*   Updated: 2019/11/15 21:08:12 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/get_next_line.h"

void	print_cell(t_cell *list)
{
	t_cell *tmp;

	printf("\ntetriminos:\n\n");
	tmp = list;
	while (tmp != NULL)
	{
		printf("x: %hhu y: %hhu pos: %d h: %d w: %d\n", tmp->x, tmp->y, tmp->pos, tmp->h, tmp->w);
		tmp = tmp->r;
	}
}

int		shift_tetr(char tetrimino[4][5], int i_sh, int j_sh)
{
	int i;
	int j;

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

void	h_and_w(uint8_t *w, uint8_t *h, char tetrimino[4][5])
{
    int i;
    int j;

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

t_cell	*new_add(t_cell *new, t_cell *list)
{
	t_cell *tmp;

	tmp = list;
	if (list == NULL)
		list = new;
	else
	{
		while(tmp->r != NULL)
			tmp = tmp->r;
		tmp->r = new;
	}
	return (list);
}

t_cell	*four_cells(char tetrimino[4][5])
{
	t_cell *new;
	t_cell *tmp;
	int i;

	i = 0;
	new = ft_cellnew(0, 0, 0, 0);
	h_and_w(&new->w,  &new->h, tetrimino);
	tmp = new;
	while (i < 3)
	{
		tmp->r = ft_cellnew(0, 0, 0, 0);
		h_and_w(&tmp->r->w,  &tmp->r->h, tetrimino);
		tmp = tmp->r;
		i++;
	}
	return (new);
}

void	one_side(char tetrimino[4][5])
{
	int i;
	int j;

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

t_cell	*index_cell(t_cell *list)
{
	int i;
	t_cell *tmp;

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

t_cell	*new_item(char tetrimino[4][5], t_cell *list)
{
	t_cell	*new;
	t_cell	*tmp;
	int		i;
	int		j;

	i = 0;
	one_side(tetrimino);
	/*
	.. print the tetrimino
	*/
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", tetrimino[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	printf("\n");
	/*
	.. end of print
	*/
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

t_cell	*make_list(int fd)
{
	char	*line;
	int		i;
	char	tetrimino[4][5];
	t_cell	*list;

	i = 1;
	list = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (i % 5 != 0)
			ft_strcpy(tetrimino[i % 5 - 1], line);
		if (i % 5 == 0)
			list = new_item(tetrimino, list);
		i++;
		free(line);
	}
	free(line);
	list = new_item(tetrimino, list);
	list = index_cell(list);
	// print tetr
	print_cell(list);
	// end
	return (list);
}
