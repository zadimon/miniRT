/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:35:15 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/16 18:44:21 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_atoi_for_f(const char *s, int *i)
{
	int	num;

	num = 0;
	while (ft_isdigit(s[*i]) && s[*i] != '\0')
	{
		num = (num * 10) + (s[*i] - '0');
		(*i)++;
	}
	return (num);
}

int	count_fraction(char *s)
{
	int	res;

	res = 0;
	while (ft_isdigit(s[res]) && s[res] != '\0')
		res++;
	return (res);
}

float	ft_atof(char *s)
{
	float	res;
	int		count;
	int		minus;
	int		i;

	res = 0;
	minus = 1;
	i = 0;
	if (s[i] == '-')
		minus = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	res = ft_atoi_for_f(s, &i);
	if (s[i] == '.')
		i++;
	else
		return (res * minus);
	count = pow(10, count_fraction(s + i));
	res = res + (float)(ft_atoi_for_f(s, &i)) / (float)count;
	return (res * minus);
}

int	ft_mod_atoi(const char *s)
{
	int	num;
	int	i;
	int	minus;

	num = 0;
	minus = 1;
	i = 0;
	if (s[i] == '-')
		minus = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]) && s[i] != '\0')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num * minus);
}
