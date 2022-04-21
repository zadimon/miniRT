/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_with_vectors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:10:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/18 23:53:35 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

float	scal_mul(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	mul_on_num(t_vec v, float n)
{
	t_vec	res;

	res = new_vec(v.x * n, v.y * n, v.z * n);
	return (res);
}

t_vec	vec_mul(t_vec v1, t_vec v2)
{
	t_vec	res;
	double	x;
	double	y;
	double	z;

	x = (v1.y * v2.z) - (v1.z * v2.y);
	y = (v1.z * v2.x) - (v1.x * v2.z);
	z = (v1.x * v2.y) - (v1.y * v2.x);
	res = new_vec(x, y, z);
	return (res);
}

t_vec	matrix_mul(t_look_at *look_at, t_vec v)
{
	t_vec	res;

	res.x = v.x * look_at->right.x + v.y * look_at->up.x
		+ v.z * look_at->or.x + look_at->camera.x;
	res.y = v.x * look_at->right.y + v.y * look_at->up.y
		+ v.z * look_at->or.y + look_at->camera.y;
	res.z = v.x * look_at->right.z + v.y * look_at->up.z
		+ v.z * look_at->or.z + look_at->camera.z;
	return (res);
}
