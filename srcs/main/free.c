/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:30:10 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 22:32:26 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_fig(t_fig *fig)
{
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;

	if (fig->type == SPHERE)
	{
		sp = (t_sp *)fig->obj;
		free(sp->sp_coor);
	}
	if (fig->type == PLANE)
	{
		pl = (t_pl *)fig->obj;
		free(pl->pl_coor);
		free(pl->pl_vec);
	}
	if (fig->type == CYLINDER)
	{
		cy = (t_cy *)fig->obj;
		free(cy->cy_coor);
		free(cy->cy_vec);
	}
	free(fig->obj);
	free(fig->rgb);
	free(fig);
}

void	ft_free_param(t_sc *sc)
{
	t_fig	*next;

	if (sc->amb)
	{
		free(sc->amb->amb_rgb);
		free(sc->amb);
	}
	if (sc->cam)
	{
		free(sc->cam->cam_coor);
		free(sc->cam->cam_vec);
		free(sc->cam);
	}
	if (sc->lig)
	{
		free(sc->lig->lig_coor);
		free(sc->lig->lig_rgb);
		free(sc->lig);
	}
	while (sc->fig)
	{
		next = sc->fig->next;
		free_fig(sc->fig);
		sc->fig = next;
	}
}

void	ft_free_str_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}
