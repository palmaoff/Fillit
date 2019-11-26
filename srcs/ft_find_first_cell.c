//
// Created by Vasya on 13.11.2019.
//

#include "fillit.h"

t_cell			*ft_find_first_cell(t_cell *cell)
{
	t_cell	*head_tetr;

	head_tetr = cell;
	while (head_tetr->l)
		head_tetr = head_tetr->l;
	return (head_tetr);
}
