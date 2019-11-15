/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_window_cleaner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souakrim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:03:55 by souakrim          #+#    #+#             */
/*   Updated: 2019/09/08 15:03:57 by souakrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		close_window(t_img **img)
{
	if (*img != NULL)
	{
		if ((*img)->ant_tex != NULL)
			SDL_DestroyTexture((*img)->ant_tex);
		if ((*img)->house_tex != NULL)
			SDL_DestroyTexture((*img)->house_tex);
		if ((*img)->ruin_tex != NULL)
			SDL_DestroyTexture((*img)->ruin_tex);
		if ((*img)->mansion_tex != NULL)
			SDL_DestroyTexture((*img)->mansion_tex);
		if ((*img)->backround_tex != NULL)
			SDL_DestroyTexture((*img)->backround_tex);
		SDL_DestroyRenderer((*img)->renderer);
		SDL_DestroyWindow((*img)->win);
		free(*img);
		*img = NULL;
		SDL_Quit();
	}
}
