//
// Created by Louvenia Oram on 21/11/2019.
//

#include "fillit.h"

void		*ft_fail_head_on_create(t_cell **headarr, int i)
{
	while (i-- >= 0)
		ft_freehead(headarr[i]);
	free(headarr);
	return (NULL);
}
