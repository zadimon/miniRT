/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:44:04 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 17:55:05 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_vport(t_sc *sc, t_vport *vport)
{
	vport->w_vport = tan(sc->cam->fov / 2 * M_PI / 180);
	vport->x_pixel = 2 / ((float)WIDTH - 1);
	vport->y_pixel = 2 / ((float)HEIGHT - 1);
}

t_look_at	*get_look_at_matrix(t_sc *sc)
{
	t_look_at	*res;

	res = malloc(sizeof(t_look_at));
	if (!(res))
		exit(put_error("Malloc error", NULL));
	res->right = vec_mul((t_vec){0, 1, 0}, *sc->cam->cam_vec);
	norm_vec(&res->right);
	res->up = vec_mul(*sc->cam->cam_vec, res->right);
	norm_vec(&res->up);
	res->camera = *sc->cam->cam_coor;
	res->or = *sc->cam->cam_vec;
	return (res);
}

t_ray	get_ray(t_look_at *look_at, t_vport *vport)
{
	float	v_x;
	float	v_y;
	t_ray	ray;

	v_x = vport->w_vport * ((float)WIDTH / (float)HEIGHT)
		* (vport->x_pixel * vport->x - 1);
	v_y = vport->w_vport * (1 - vport->y_pixel * vport->y);
	ray.v_d = new_vec(v_x, v_y, 1);
	ray.v_o = look_at->camera;
	ray.v_d = matrix_mul(look_at, ray.v_d);
	ray.v_d = vec_sub(ray.v_d, ray.v_o);
	ray.t_max = MAXFLOAT;
	ray.t_min = 0.1;
	norm_vec(&ray.v_d);
	return (ray);
}
