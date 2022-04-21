/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:51:53 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 23:45:41 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec	new_vec(float x, float y, float z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	res;

	res = new_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (res);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec	res;

	res = new_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (res);
}

float	vec_len(t_vec *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

void	norm_vec(t_vec *vec)
{
	float	len;

	len = vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}
