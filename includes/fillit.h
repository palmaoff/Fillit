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
# include <sys/uio.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

/*
** pos - one of 0...18 tetramino;
 ** w, h - wide & height of tetramino
** x, y - coordinates of cell in map (max map - 13x13);
**
 */

typedef struct					s_cell
{
	__uint8_t			pos;
	__uint8_t			w;
	__uint8_t			h;
	__uint8_t			x;
	__uint8_t			y;
	__uint8_t			inc;
	struct s_cell		*l;
	struct s_cell   	*r;
	struct s_cell		*u;
	struct s_cell		*d;
	struct s_cell		*col;
}								t_cell;

typedef struct					s_map
{
	struct s_cell	*cell;
	struct s_map	*next;
	struct s_map	*prev;
}								t_map;

t_cell				*ft_cellnew(uint8_t w, uint8_t h, uint8_t x, uint8_t y);
void				ft_tetadd(t_cell *map, t_cell *new);
void				ft_lineadd(t_cell **alst, t_cell *new);
void				ft_tetfree(t_cell **begin_cell);
__uint8_t			ft_read_input(int const fd, t_cell *tetris);
t_cell 				**create_header(int dim);
t_cell				*ft_get_hd_xy(t_cell *cell,  t_cell **head, int size);
void				ft_freecell(t_cell *cell);
void				ft_colfree(t_cell *head);
void				ft_freehead(t_cell *head);
t_cell				*ft_find_first_cell(t_cell *cell);
void				ft_exclude_header(t_cell *cell);
void				ft_exclude_3_headers(t_cell *tetr);
void				ft_exclude_row(t_cell *tetr);
t_cell				*ft_get_hd_up(t_cell *cell);
void				ft_exclude_pos_block(t_cell *head, t_cell *tetr);
void				ft_exclude_head_rows_pos(t_cell *head, t_cell *tetr);
void				ft_exclude_all_headers_and_rows(t_cell *head, t_cell *tetr);
int					ft_alg(t_cell *head, int pos_num, int pos, t_cell **map);
void				ft_include_all_headers_and_rows(t_cell *head0, t_cell *head, t_cell *tetr);
void				ft_include_header(t_cell *cell);
void				ft_include_row(t_cell *tetr);
void				ft_include_header(t_cell *cell);
void				ft_include_pos_block(t_cell *head, int pos);
void				ft_include_head_rows_pos(t_cell *head, int pos);
t_cell				*ft_create_head_0(uint8_t inc, uint8_t x, uint8_t y);
void				*ft_fail_head_on_create(t_cell **headarr, int i);
t_cell				**ft_create_header(int dim);
void				ft_free_all(t_cell **map, int size);
void				ft_free_cells_up(t_cell *head, t_cell *cell);
int 				ft_check_heads_tetr_w(t_cell *cell);

void	            print_cell(t_cell *list); // tmp function
void 				print_map(t_cell **map, int dim); // tmp function

t_cell				*index_cell(t_cell *list);
void				one_side(char tetrimino[4][5]);
int					check_input(int fd);
t_cell				*make_list(int fd);
t_cell				*new_item(char tetrimino[4][5], t_cell *list);
int					shift_tetr(char tetrimino[4][5], int i_sh, int j_sh);
t_cell				*new_add(t_cell *new, t_cell *list);
t_cell				*four_cells(char tetrimino[4][5]);
void                h_and_w(uint8_t *w, uint8_t *h, char tetrimino[4][5]);

void                input(t_cell **map, t_cell *cell, int dim, int k);
void 				inputting(t_cell **map, t_cell *cell, int dim);
int					check_gap(t_cell *cell, int i, int dim);
int					inc_cell(t_cell *cell, int i, int dim);
void				end_head(t_cell **map, int dim);

void				ft_freelist(t_cell *list);
void				ft_print(t_cell **map, int dim);

#endif
