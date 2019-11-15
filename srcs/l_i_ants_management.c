/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_ants_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:58:25 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 14:58:31 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			manage_ants(t_path_tab **paths, int ants)
{
	int		i;
	int		moves;
	int		psize;

	while (ants)
	{
		i = -1;
		while (paths[++i] && ants)
		{
			psize = path_size(paths[i]);
			if (i == 0)
			{
				++(paths[i]->nb_ants);
				--ants;
				moves = psize + paths[i]->nb_ants - 2;
			}
			else if (moves >= (psize - 1))
			{
				++(paths[i]->nb_ants);
				--ants;
			}
		}
	}
	return (moves);
}

void		select_path(t_path_tab ***paths, int ants, t_path_tab ***s)
{
	static int		moves = -1;
	int				tmp;

	tmp = manage_ants(*paths, ants);
	if (moves == -1)
	{
		moves = tmp;
		*s = *paths;
	}
	else if (moves > tmp)
	{
		moves = tmp;
		delete_path_tab(s);
		*s = *paths;
	}
	else
		delete_path_tab(paths);
}

void		del_ants(t_ants **ants)
{
	if (*ants)
	{
		free(*ants);
		ants = NULL;
	}
}

void		del_all_ants(t_ants **ants)
{
	t_ants	*todel;

	while (*ants)
	{
		todel = *ants;
		*ants = (*ants)->next;
		del_ants(&todel);
	}
}
