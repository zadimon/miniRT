/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:58:06 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 19:08:21 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

char	**check_color_params(char *param)
{
	char	**nums;
	int		i;

	nums = ft_split(param, ',');
	i = 0;
	while (nums[i])
		i++;
	if (i != 3)
		exit(put_error("Invalid amount of colors", NULL));
	i = 0;
	while (nums[i])
	{
		if (!num_is_int(nums[i]))
			exit(put_error("Invalid color: ", nums[i]));
		i++;
	}
	return (nums);
}

t_rgb	*create_col(char *param)
{
	t_rgb	*col;
	char	**nums;

	col = malloc(sizeof(t_rgb));
	if (!(col))
		exit(put_error("Malloc error", NULL));
	nums = check_color_params(param);
	col->r = ft_mod_atoi(nums[0]);
	if (col->r < 0 || col->r > 255)
		exit(put_error("Color is out of range: ", nums[0]));
	col->g = ft_mod_atoi(nums[1]);
	if (col->g < 0 || col->g > 255)
		exit(put_error("Color is out of range: ", nums[1]));
	col->b = ft_mod_atoi(nums[2]);
	if (col->b < 0 || col->b > 255)
		exit(put_error("Color is out of range: ", nums[2]));
	ft_free_str_ar(nums);
	return (col);
}
