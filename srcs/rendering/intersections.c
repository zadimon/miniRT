/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:38:21 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 18:44:49 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	sphere_intersection(t_sp *sp, t_ray *ray, float *t)
{
	t_equ	equ;
	float	tmp;

	equ = equ_for_sp(sp, ray);
	if (solve_quad_equ(&equ) == 0)
		return (0);
	if (equ.t1 > equ.t2)
	{
		tmp = equ.t1;
		equ.t1 = equ.t2;
		equ.t2 = tmp;
	}
	if (equ.t1 < 0)
	{
		if (equ.t2 < 0)
			return (0);
		*t = equ.t2;
	}
	else
		*t = equ.t1;
	return (1);
}

int	plane_intersection(t_pl *pl, t_ray *ray, float *t)
{
	float	denom;
	t_vec	v_pl;

	denom = scal_mul(*pl->pl_vec, ray->v_d);
	if (fabs(denom) > 1e-6)
	{
		v_pl = vec_sub(*pl->pl_coor, ray->v_o);
		*t = scal_mul(v_pl, *pl->pl_vec) / denom;
		if (*t >= 0)
			return (1);
	}
	return (0);
}

int	cylinder_intersection(t_cy *cy, t_ray *ray, float *t)
{
	t_equ	equ;
	t_vec	v_cy;
	float	tmp;

	v_cy = vec_sub(ray->v_o, *cy->cy_coor);
	equ = equ_for_cy(cy, ray, v_cy);
	if (!solve_quad_equ(&equ))
		return (0);
	if (equ.t1 > equ.t2)
	{
		tmp = equ.t1;
		equ.t1 = equ.t2;
		equ.t2 = tmp;
	}
	if (!check_height(cy, ray, v_cy, &equ))
		return (0);
	if (equ.t1 < 0)
	{
		if (equ.t2 < 0)
			return (0);
		*t = equ.t2;
	}
	else
		*t = equ.t1;
	return (1);
}

int	get_intersection(t_fig *fig, t_ray *ray, float *t)
{
	if (fig->type == SPHERE)
		return (sphere_intersection((t_sp *) fig->obj, ray, t));
	if (fig->type == PLANE)
		return (plane_intersection((t_pl *)fig->obj, ray, t));
	if (fig->type == CYLINDER)
		return (cylinder_intersection((t_cy *)fig->obj, ray, t));
	return (0);
}

int	check_intersections(t_sc *sc, t_ray *ray)
{
	t_fig	*fig;
	float	t;

	ray->closest_fig = NULL;
	fig = sc->fig;
	while (fig)
	{
		if (fig->is_check && get_intersection(fig, ray, &t))
		{
			if (t > ray->t_min && t < ray->t_max)
			{
				ray->closest_fig = fig;
				ray->t_max = t;
			}
		}
		fig = fig->next;
	}
	if (ray->closest_fig)
		return (1);
	else
		return (0);
}
