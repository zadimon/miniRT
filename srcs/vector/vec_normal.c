/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:41:41 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 16:40:54 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec	get_sphere_normal(t_vec v_p, t_sp *sp)
{
	t_vec	v_n;

	v_n = vec_sub(v_p, *sp->sp_coor);
	norm_vec(&v_n);
	return (v_n);
}

t_vec	get_plane_normal(t_pl *pl)
{
	return (*pl->pl_vec);
}

t_vec	get_cylinder_normal(t_vec v_p, t_cy *cy)
{
	t_vec	v_n;
	t_vec	t1;
	t_vec	t2;

	t1 = vec_sub(v_p, *cy->cy_coor);
	t2 = mul_on_num(*cy->cy_vec,
			scal_mul(*cy->cy_vec, t1));
	v_n = vec_sub(t1, t2);
	norm_vec(&v_n);
	return (v_n);
}

t_vec	get_normal(t_vec v_p, t_ray *ray)
{
	if (ray->closest_fig->type == SPHERE)
		return (get_sphere_normal(v_p, (t_sp *)ray->closest_fig->obj));
	if (ray->closest_fig->type == PLANE)
		return (get_plane_normal((t_pl *)ray->closest_fig->obj));
	if (ray->closest_fig->type == CYLINDER)
		return (get_cylinder_normal(v_p, (t_cy *)ray->closest_fig->obj));
	return ((t_vec){0, 0, 0});
}
