/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_sort_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:03:18 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:03:19 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	sort_paths(t_path_tab **tab)
{
	t_path_tab	*tmp;
	int			i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (path_size(tab[i]) > path_size(tab[i + 1]))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			++i;
	}
}
