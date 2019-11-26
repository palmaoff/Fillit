/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_elemcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:52:30 by loram             #+#    #+#             */
/*   Updated: 2019/09/21 15:56:42 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_elemcpy(t_list *elem)
{
	return (ft_lstnew(elem->content, sizeof(elem->content),
			elem->fd, elem->eof));
}
