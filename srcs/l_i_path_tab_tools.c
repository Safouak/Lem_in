/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_path_tab_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:02:48 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:02:56 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			path_size(t_path_tab *paths)
{
	int			len;
	t_path_tab	*tmp;

	len = 0;
	tmp = paths;
	while (tmp)
	{
		len += tmp->size;
		tmp = tmp->next;
	}
	return (len);
}

int			get_room(t_path_tab *paths, int room)
{
	int			n;
	t_path_tab	*tmp;

	tmp = paths;
	n = room;
	if (n < PATH_BUFF)
		return ((tmp->tab)[n]);
	else
	{
		while (n >= PATH_BUFF)
		{
			n -= PATH_BUFF;
			tmp = tmp->next;
		}
		return ((tmp->tab)[n]);
	}
}
