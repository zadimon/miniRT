/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:37:57 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 16:01:22 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	rgb(int color, char level)
{
	if (level == 'R')
		return ((color >> 16) & 0xFF);
	if (level == 'G')
		return ((color >> 8) & 0xFF);
	if (level == 'B')
		return (color & 0xFF);
	return (0);
}

int	add_color(int color, float coef)
{
	int	r;
	int	g;
	int	b;

	r = rgb(color, 'R') + coef;
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = rgb(color, 'G') + coef;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = rgb(color, 'B') + coef;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (create_rgb(r, g, b));
}

int	add_color3(int c1, int c2, int c3)
{
	int	r;
	int	g;
	int	b;

	r = rgb(c1, 'R') + rgb(c2, 'R') + rgb(c3, 'R');
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = rgb(c1, 'G') + rgb(c2, 'G') + rgb(c3, 'G');
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = rgb(c1, 'B') + rgb(c2, 'B') + rgb(c3, 'B');
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (create_rgb(r, g, b));
}

int	mul_color(t_rgb col, float coef)
{
	int	r;
	int	g;
	int	b;
	int	color;

	color = create_rgb(col.r, col.g, col.b);
	r = rgb(color, 'R') * coef;
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = rgb(color, 'G') * coef;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = rgb(color, 'B') * coef;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (create_rgb(r, g, b));
}

int	mul_int_color(int color1, float coef)
{
	int	r;
	int	g;
	int	b;

	r = rgb(color1, 'R') * coef;
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = rgb(color1, 'G') * coef;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = rgb(color1, 'B') * coef;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (create_rgb(r, g, b));
}
