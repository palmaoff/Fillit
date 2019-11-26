
#include "../includes/fillit.h"

t_cell				*ft_cellnew(uint8_t w, uint8_t h, uint8_t x,
								uint8_t y)
{
	t_cell		*new;

	if ((new = (t_cell *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->pos = 0;
	new->w = w;
	new->h = h;
	new->x = x;
	new->y = y;
	new->inc = 0;
	new->l = NULL;
	new->r = NULL;
	new->u = NULL;
	new->d = NULL;
	new->col = NULL;
	return (new);
}
