/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:59:54 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 14:59:56 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_bonus(int ac, char **av, t_adjmatrix *mat, t_vertex *vtx)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "--graphic"))
			create_graph_setting(mat, &mat->img, vtx);
		else if (!ft_strcmp(av[i], "--nblines"))
			mat->opt_nblines = true;
		else if (!ft_strcmp(av[i], "--paths"))
			mat->opt_paths = true;
	}
}

void	print_opts(t_adjmatrix *mat, t_path_tab **paths, int nlines, char **out)
{
	int		i;
	int		room;
	int		room_id;

	if (mat->opt_nblines == true)
		ft_printf("\nMap solved in %d lines\n", nlines);
	if (mat->opt_paths == true)
	{
		ft_printf("\nPaths used :\n");
		i = -1;
		while (paths[++i])
		{
			room_id = -1;
			room = 0;
			while (room_id != mat->end)
			{
				room_id = get_room(paths[i], room);
				if (room != 0)
					ft_printf(" -> ");
				ft_printf("%s", out[room_id]);
				++room;
			}
			write(1, "\n\n", 2);
		}
	}
}
