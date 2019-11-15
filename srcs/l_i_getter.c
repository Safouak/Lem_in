/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:00:21 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:00:24 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex	*get_last_vertex(t_vertex *vtx)
{
	t_vertex	*tmp;

	tmp = vtx;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_vertex	*get_vertex(t_vertex *vtx, char *name)
{
	t_vertex	*tmp;

	tmp = vtx;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
