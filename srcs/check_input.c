/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:11:51 by eflorean          #+#    #+#             */
/*   Updated: 2019/10/21 15:11:56 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/get_next_line.h"

static	int	check_line(char *line)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

static	int	neighborhood(char t[4][5], int i, int j)
{
	int count;

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

static	int	check_matrix(char a[4][5])
{
	int i;
	int j;
	int sum;
	int count;

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

int	check_input(int fd)
{
	char	*line;
	int		i;
	char	tetrisine[4][5];

	i = 1;
	line = NULL;
	while ((get_next_line(fd, &line)) > 0 && i)
	{
		if ((i % 5 != 0) && ((ft_strlen(line) != 4) || !(check_line(line))))
			i = -1;
		else if (i % 5 != 0)
			ft_strcpy(tetrisine[i % 5 - 1], line);
		else if ((i % 5 == 0) && (ft_strlen(line) != 0))
			i = -1;
		else if ((i % 5 == 0 && !check_matrix(tetrisine)) || i > 130)
			i = -1;
		i++;
		free(line);
	}
	i = (!check_matrix(tetrisine) || i == 0 || i > 130) ? 0 : i;
	if (line)
		free(line);
	close(fd);
	return (i == 0) ? 0 : 1;
}
