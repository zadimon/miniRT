/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:00:54 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 16:01:12 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	add_color2(int c1, int c2)
{
	int	r;
	int	g;
	int	b;

	r = rgb(c1, 'R') + rgb(c2, 'R');
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = rgb(c1, 'G') + rgb(c2, 'G');
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = rgb(c1, 'B') + rgb(c2, 'B');
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (create_rgb(r, g, b));
}
