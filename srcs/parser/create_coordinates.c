/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:31:21 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 19:08:49 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

char	**check_coor_params(char *param)
{
	char	**nums;
	int		i;

	nums = ft_split(param, ',');
	i = 0;
	while (nums[i])
		i++;
	if (i != 3)
		exit(put_error("Invalid amount of coordinates", NULL));
	i = 0;
	while (nums[i])
	{
		if (!num_is_float(nums[i]))
			exit(put_error("Invalid coordinate: ", nums[i]));
		i++;
	}
	return (nums);
}

t_vec	*create_coor(char *param)
{
	t_vec	*coor;
	char	**nums;

	coor = malloc(sizeof(t_vec));
	if (!(coor))
		exit(put_error("Malloc error", NULL));
	nums = check_coor_params(param);
	coor->x = ft_atof(nums[0]);
	coor->y = ft_atof(nums[1]);
	coor->z = ft_atof(nums[2]);
	ft_free_str_ar(nums);
	return (coor);
}
