/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:03:06 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:03:08 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path_tab	**solver(t_adjmatrix *mat)
{
	int			i;
	t_path_tab	**path_tab;
	t_path_tab	**saved;

	i = 1;
	saved = NULL;
	if (mat && mat->start != -1 && mat->end != -1 && mat->start != mat->end
		&& mat->tab)
	{
		while (bfs(mat, mat->start, mat->end) != false)
		{
			if ((path_tab = get_path_tab(mat, i)) == NULL)
				return (NULL);
			++i;
			if (path_size(path_tab[0]) == 2)
			{
				path_tab[0]->nb_ants = mat->ants;
				return (path_tab);
			}
			select_path(&path_tab, mat->ants, &saved);
		}
	}
	return (saved);
}
