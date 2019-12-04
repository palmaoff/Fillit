/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:04:34 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/02 15:04:42 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void				ft_search(t_cell *cell, int dim, int k)
{
	int			alg;
	t_cell		**head;

	alg = 0;
	head = NULL;
	while (!alg)
	{
		if (head != NULL)
			ft_free_all(head, (dim - 1) * (dim - 1));
		head = ft_create_header(dim);
		input(head, cell, dim, k);
		alg = ft_alg(head[0], 1, k, head);
		dim++;
	}
	ft_print(head, dim - 1);
	ft_freelist(cell);
	ft_free_all(head, (dim - 1) * (dim - 1));
}

int						main(int ac, char **av)
{
	t_cell		*cell;
	int			k;
	int			dim;
	int			fd;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = -1;
	if (!(k = check_input(fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	cell = make_list(fd);
	dim = dim_make(k, cell);
	ft_search(cell, dim, k);
	return (0);
}
