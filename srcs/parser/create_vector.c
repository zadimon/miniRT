/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:36:04 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/16 18:44:08 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

char	**check_vector_params(char *param)
{
	char	**nums;
	int		i;

	nums = ft_split(param, ',');
	i = 0;
	while (nums[i])
		i++;
	if (i != 3)
		exit(put_error("Invalid amount of vector coordinates", NULL));
	i = 0;
	while (nums[i])
	{
		if (!num_is_float(nums[i]))
			exit(put_error("Invalid vector coordinate: ", nums[i]));
		i++;
	}
	return (nums);
}

t_vec	*create_vec(char *param)
{
	t_vec	*vec;
	char	**nums;

	vec = malloc(sizeof(t_vec));
	if (!(vec))
		exit(put_error("Malloc error", NULL));
	nums = check_vector_params(param);
	vec->x = ft_atof(nums[0]);
	if (vec->x < -1.0 || vec->x > 1.0)
		exit(put_error("Vector coordinates is out of range: ", nums[0]));
	vec->y = ft_atof(nums[1]);
	if (vec->y < -1.0 || vec->y > 1.0)
		exit(put_error("Vector coordinates is out of range: ", nums[1]));
	vec->z = ft_atof(nums[2]);
	if (vec->z < -1.0 || vec->z > 1.0)
		exit(put_error("Vector coordinates is out of range: ", nums[2]));
	ft_free_str_ar(nums);
	return (vec);
}
