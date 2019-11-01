/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:18:19 by eflorean          #+#    #+#             */
/*   Updated: 2019/10/21 16:18:22 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"

int		check_input(int fd);
void	make_list(int fd);

typedef struct  s_tetr
{
    size_t		h;
	size_t		w;
    long long int	t;
    struct t_fd	*next;
} 				t_tetr;

t_tetr *new_item(char	tetrisine[4][5]);

#endif