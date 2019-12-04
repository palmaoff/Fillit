/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:02:27 by loram             #+#    #+#             */
/*   Updated: 2019/11/20 00:29:28 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"
# include <stdlib.h>
# include "get_next_line.h"

typedef struct		s_cell
{
	int					pos;
	int					w;
	int					h;
	int					x;
	int					y;
	int					inc;
	struct s_cell		*l;
	struct s_cell		*r;
	struct s_cell		*d;
	struct s_cell		*col;
}					t_cell;

t_cell				*ft_cellnew(int w, int h, int x, int y);
int					check_input(int fd);
t_cell				*make_list(int fd);
t_cell				*new_add(t_cell *new, t_cell *list);
t_cell				*four_cells(char tetrimino[4][5]);
void				ft_freecell(t_cell *cell);
void				ft_freehead(t_cell *head);
t_cell				*ft_find_first_cell(t_cell *cell);
void				ft_exclude_row(t_cell *tetr, int inc);
t_cell				*ft_get_hd_up(t_cell *cell);
void				ft_excl_all_h_and_r(t_cell *head, t_cell *tetr,
										int pos_num);
int					ft_alg(t_cell *head, int pos_num, int pos, t_cell **map);
void				ft_inc_all_h_and_r(t_cell *head0, t_cell *tetr,
										int pos_num);
void				ft_include_row(t_cell *tetr);
void				input(t_cell **map, t_cell *cell, int dim, int k);
void				inputting(t_cell **map, t_cell *cell, int dim);
t_cell				**ft_create_header(int dim);
void				ft_free_all(t_cell **map, int size);
int					ft_check_heads_tetr_inc(t_cell *cell);
void				ft_freelist(t_cell *list);
void				ft_print(t_cell **map, int dim);
int					dim_make(int k, t_cell *cell);
int					inc_cell(t_cell *cell, int i, int dim);
void				one_side(char tetrimino[4][5]);
void				ft_freearea(char **area, int dim);
int					check_matrix(char **a);

#endif
