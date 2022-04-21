/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:23:13 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/20 15:05:37 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	last_sp(t_sc *sc, t_sp *sp, char *color)
{
	t_fig	*last;
	t_fig	*new;

	new = malloc(sizeof(t_fig));
	if (!(new))
		exit(put_error("Malloc error", NULL));
	new->is_check = 1;
	new->type = SPHERE;
	new->obj = sp;
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

void	create_sp(t_sc *sc, char **param)
{
	t_sp	*sp;
	int		i;

	sp = malloc(sizeof(t_sp));
	if (!(sp))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		exit(put_error("Invalid amount of sphere parameters", NULL));
	sp->sp_coor = create_coor(param[1]);
	if (!num_is_float(param[2]))
		exit(put_error("Invalid sphere diameter: ", param[2]));
	sp->sp_r = ft_atof(param[2]) / 2;
	if (sp->sp_r < 0)
		exit(put_error("Sphere diameter less than zero: ", param[2]));
	last_sp(sc, sp, param[3]);
}
