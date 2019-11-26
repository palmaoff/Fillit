/*
 * headarr начинается с пустого листа, headarr[1] соответствует т.(0, 0)
 */
#include "../includes/fillit.h"

static void			add_headarr_params(t_cell **headarr, int size)
{
	int 		i;

	i = 1;
	while (i < (size + 1))
	{
		headarr[i - 1]->r = headarr[i];
		headarr[i]->l = headarr[i - 1];
		headarr[i]->inc = 1;
		i++;
	}

}

t_cell				**ft_create_header(int dim)
{
	int			y;
	int 		x;
	int 		k;
	t_cell		**headarr;

	if (!(headarr = (t_cell **)malloc((dim * dim + 1) * sizeof(t_cell *))))
		return (NULL);
	if (!(headarr[0] = ft_create_head_0(2, 0, 0)))
		return(ft_fail_head_on_create(headarr, 0));
	y = 0;
	k = 1;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			if (!(headarr[k++] = ft_cellnew(0, 0, x, y)))
				return (ft_fail_head_on_create(headarr, k - 1));
			x++;
		}
		y++;
	}
	add_headarr_params(headarr, dim * dim);
	return (headarr);
}

