/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:17:10 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/20 15:06:03 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	last_pl(t_sc *sc, t_pl *pl, char *color)
{
	t_fig	*last;
	t_fig	*new;

	new = malloc(sizeof(t_fig));
	if (!(new))
		exit(put_error("Malloc error", NULL));
	new->is_check = 1;
	new->type = PLANE;
	new->obj = pl;
	new->rgb = create_col(color);
	new->next = NULL;
	last = sc->fig;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		sc->fig = new;
}

void	create_pl(t_sc *sc, char **param)
{
	t_pl	*pl;
	int		i;

	pl = malloc(sizeof(t_pl));
	if (!(pl))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		exit(put_error("Invalid amount of plane parameters", NULL));
	pl->pl_coor = create_coor(param[1]);
	pl->pl_vec = create_vec(param[2]);
	last_pl(sc, pl, param[3]);
}
