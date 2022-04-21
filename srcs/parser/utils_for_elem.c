/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:13:01 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/16 18:44:38 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_isint(char c)
{
	if (ft_isdigit(c) || c == '+'
		|| c == '-')
		return (1);
	return (0);
}

int	ft_isfloat(char c)
{
	if (ft_isdigit(c) || c == '+'
		|| c == '-' || c == '.')
		return (1);
	return (0);
}

int	num_is_int(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isint(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	num_is_float(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isfloat(num[i]))
			return (0);
		i++;
	}
	return (1);
}
