/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:01:13 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:01:16 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_input(t_input *input)
{
	t_input *tmp;

	tmp = input;
	while (tmp)
	{
		ft_putendl_fd(tmp->line, 1);
		tmp = tmp->next;
	}
}

static int	helper(t_vertex *vtx, t_adjmatrix *mat, t_path_tab **paths)
{
	if (mat->ants > 0 && (paths = solver(mat)) == NULL)
	{
		close_window(&(mat->img));
		clean_memory(&mat, &vtx);
		ft_printf("ERROR\n");
		return (false);
	}
	print_input(mat->input);
	if (paths && ((path_size(paths[0]) == 2
		&& !output_all_ants(paths, vtx, mat)) || !output_ants(paths, vtx, mat)))
	{
		if (mat->img != NULL)
			end_wait(&(mat->img));
	}
	clean_memory(&mat, &vtx);
	(paths) ? delete_path_tab(&paths) : 0;
	return (true);
}

int			main(int ac, char **av)
{
	t_vertex	*vtx;
	t_adjmatrix	*mat;
	t_path_tab	**paths;

	vtx = NULL;
	paths = NULL;
	if (init_adjmatrix(&mat))
		return (false);
	if (parser(&vtx, &mat) == false)
	{
		clean_memory(&mat, &vtx);
		ft_printf("ERROR\n");
		return (false);
	}
	mat->img = NULL;
	get_bonus(ac, av, mat, vtx);
	return (helper(vtx, mat, paths));
}
