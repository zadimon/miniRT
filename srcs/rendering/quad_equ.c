/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad_equ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:40:43 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 16:38:07 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_height(t_cy *cy, t_ray *ray, t_vec v_cy, t_equ *equ)
{
	float	m1;
	float	m2;

	ray->m = 1;
	m1 = scal_mul(mul_on_num(ray->v_d, equ->t1), *cy->cy_vec)
		+ scal_mul(v_cy, *cy->cy_vec);
	m2 = scal_mul(mul_on_num(ray->v_d, equ->t2), *cy->cy_vec)
		+ scal_mul(v_cy, *cy->cy_vec);
	if (m1 < 0 || m1 > cy->cy_hei)
		ray->m = -1;
	if ((m1 < 0 || m1 > cy->cy_hei) && (m2 < 0 || m2 > cy->cy_hei))
		return (0);
	if (m1 < 0 || m1 > cy->cy_hei)
		equ->t1 = equ->t2;
	return (1);
}

int	solve_quad_equ(t_equ *equ)
{
	float	di;

	di = equ->b * equ->b - 4 * equ->a * equ->c;
	if (di < 0)
		return (0);
	else if (di == 0)
	{
		equ->t1 = -equ->b / (2 * equ->a);
		equ->t2 = equ->t1;
	}
	else
	{
		equ->t1 = (-equ->b + sqrt(di)) / (2 * equ->a);
		equ->t2 = (-equ->b - sqrt(di)) / (2 * equ->a);
	}
	return (1);
}

t_equ	equ_for_sp(t_sp *sp, t_ray *ray)
{
	t_vec	v_sp;
	t_equ	equ;

	v_sp = vec_sub(ray->v_o, *sp->sp_coor);
	equ.a = scal_mul(ray->v_d, ray->v_d);
	equ.b = 2 * scal_mul(ray->v_d, v_sp);
	equ.c = scal_mul(v_sp, v_sp) - sp->sp_r * sp->sp_r;
	equ.t1 = 0;
	equ.t2 = 0;
	return (equ);
}

t_equ	equ_for_cy(t_cy *cy, t_ray *ray, t_vec v_cy)
{
	t_equ	equ;

	equ.a = scal_mul(ray->v_d, ray->v_d) - scal_mul(ray->v_d, *cy->cy_vec)
		* scal_mul(ray->v_d, *cy->cy_vec);
	equ.b = 2 * (scal_mul(ray->v_d, v_cy) - scal_mul(ray->v_d, *cy->cy_vec)
			* scal_mul(v_cy, *cy->cy_vec));
	equ.c = scal_mul(v_cy, v_cy) - scal_mul(v_cy, *cy->cy_vec)
		* scal_mul(v_cy, *cy->cy_vec) - cy->cy_r * cy->cy_r;
	equ.t1 = 0;
	equ.t2 = 0;
	return (equ);
}
