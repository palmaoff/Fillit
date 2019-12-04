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

int				check_line(char *line)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

static char		**make_matrix(void)
{
	char	**m;
	size_t	i;

	i = 0;
	m = (char **)malloc(4 * sizeof(char *));
	while (i < 4)
	{
		*(m + i) = (char *)malloc(5 * sizeof(char));
		ft_bzero(*(m + i), 5);
		i++;
	}
	return (m);
}

static void		ft_clean_matrix(char **tetrisine)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(tetrisine[i], 5);
		i++;
	}
}

static int		validation(char **tetrisine, int fd, char *line)
{
	int		i;

	i = 1;
	while ((get_next_line(fd, &line)) > 0 && i)
	{
		if ((i % 5 != 0) && ((ft_strlen(line) != 4) || !(check_line(line))))
			i = -1;
		else if (i % 5 != 0)
			ft_strcpy(tetrisine[i % 5 - 1], line);
		else if ((i % 5 == 0) && (ft_strlen(line) != 0))
			i = -1;
		else if (i % 5 == 0 && !check_matrix(tetrisine))
			i = -1;
		if (i % 5 == 0)
			ft_clean_matrix(tetrisine);
		i++;
		free(line);
	}
	free(line);
	return (i);
}

int				check_input(int fd)
{
	char	*line;
	int		i;
	char	**tetrisine;

	line = NULL;
	tetrisine = make_matrix();
	i = validation(tetrisine, fd, line);
	if (fd > 0)
		i = (!check_matrix(tetrisine) || i == 0 || i > 130) ? 0 : i;
	ft_freearea(tetrisine, 4);
	close(fd);
	return (i == 0) ? 0 : i / 5;
}
