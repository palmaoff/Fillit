
#include "../includes/fillit.h"

t_cell				*ft_create_head_0(uint8_t inc, uint8_t x, uint8_t y)
{
	t_cell		*new;

	if ((new = (t_cell *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->pos = 0;
	new->w = 0;
	new->h = 0;
	new->x = x;
	new->y = y;
	new->inc = 2;
	new->l = NULL;
	new->r = NULL;
	new->u = NULL;
	new->d = NULL;
	new->col = NULL;
	return (new);
}
