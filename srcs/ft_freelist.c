//
// Created by Emilee Florean on 24/11/2019.
//

#include <includes/fillit.h>

void    ft_freelist(t_cell *list)
{
    t_cell  *tmp;

    while (list != NULL)
    {
        tmp = list;
        list = list->r;
        free(tmp);
    }
}
