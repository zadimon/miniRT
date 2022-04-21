/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:25:33 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/20 15:05:56 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	last_cy(t_sc *sc, t_cy *cy, char *color)
{
	t_fig	*last;
	t_fig	*new;

	new = malloc(sizeof(t_fig));
	if (!(new))
		exit(put_error("Malloc error", NULL));
	new->is_check = 1;
	new->type = CYLINDER;
	new->obj = cy;
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

void	get_diam_and_hei(t_cy *cy, char **param)
{
	if (!num_is_float(param[3]))
		exit(put_error("Invalid cylinder diameter: ", param[3]));
	cy->cy_r = ft_atof(param[3]) / 2;
	if (cy->cy_r < 0)
		exit(put_error("Cylinder diameter less than zero: ", param[3]));
	if (!num_is_float(param[4]))
		exit(put_error("Invalid cylinder height: ", param[4]));
	cy->cy_hei = ft_atof(param[4]);
	if (cy->cy_hei < 0)
		exit(put_error("Cylinder height less than zero: ", param[4]));
}

void	create_cy(t_sc *sc, char **param)
{
	t_cy	*cy;
	int		i;

	cy = malloc(sizeof(t_cy));
	if (!(cy))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 6)
		exit(put_error("Invalid amount of cylinder parameters", NULL));
	cy->cy_coor = create_coor(param[1]);
	cy->cy_vec = create_vec(param[2]);
	get_diam_and_hei(cy, param);
	last_cy(sc, cy, param[5]);
}
