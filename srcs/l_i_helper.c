/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:00:45 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:00:48 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		insert_ants_helper(t_ants *new, t_path_tab **path,
		int i, int *number)
{
	new->path = path[i];
	new->room = 0;
	new->number = ++(*number);
	new->next = NULL;
	new->pasx = -1;
	new->pasy = -1;
}

void		init_adjacency_tab_helper(t_adjmatrix **mat, int i)
{
	(*mat)->tab[i]->id = -1;
	(*mat)->tab[i]->weight = -1;
	(*mat)->tab[i]->father_id = -1;
	(*mat)->tab[i]->next = NULL;
	(*mat)->visited[i] = false;
	(*mat)->old_visited[i] = false;
}
