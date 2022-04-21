/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:03 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 18:05:20 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	diffuse_light(t_vec v_n, t_vec v_l)
{
	float	n_dot_l;

	n_dot_l = scal_mul(v_n, v_l);
	return (n_dot_l);
}

t_ray	get_l_ray(t_vec v_p, t_vec v_l)
{
	t_ray	l_ray;

	l_ray.v_o = v_p;
	l_ray.v_d = v_l;
	norm_vec(&l_ray.v_d);
	l_ray.t_max = HUGE_VAL;
	l_ray.t_min = 1e-6;
	return (l_ray);
}

int	get_shadow(t_sc *sc, t_fig *closest, t_ray l_ray)
{
	closest->is_check = 0;
	if (check_intersections(sc, &l_ray))
	{
		closest->is_check = 1;
		return (1);
	}
	closest->is_check = 1;
	return (0);
}

float	highlight(t_lig *lig, t_vec v_n, t_vec v_l, t_vec v_v)
{
	float	r_dot_v;
	t_vec	v_r;

	v_r = vec_sub(mul_on_num(v_n, 2 * scal_mul(v_n, v_l)), v_l);
	r_dot_v = scal_mul(v_r, v_v);
	return (pow(fmax(r_dot_v, 0), SELECT_COEF) * lig->brig);
}

int	get_color_with_brig(t_sc *sc, t_ray *ray, t_to_lig to_lig)
{
	int		color;

	if (get_shadow(sc, ray->closest_fig, get_l_ray(to_lig.v_p, to_lig.v_l)))
	{
		color = add_color(add_color3
				(mul_color(*ray->closest_fig->rgb, sc->amb->amb_ratio),
					mul_color(*ray->closest_fig->rgb,
						diffuse_light(to_lig.v_n, to_lig.v_l) * DIFF_COEF),
					0), SHADOW_COEF);
	}
	else
	{
		color = add_color3
			(mul_color(*ray->closest_fig->rgb, sc->amb->amb_ratio),
				mul_color(*ray->closest_fig->rgb,
					diffuse_light(to_lig.v_n, to_lig.v_l) * DIFF_COEF),
				mul_color(*ray->closest_fig->rgb,
					highlight(sc->lig, to_lig.v_n,
						to_lig.v_l, to_lig.v_v) * SPEC_COEF));
	}
	return (color);
}
