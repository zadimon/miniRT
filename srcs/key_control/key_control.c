/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:03:02 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/16 23:19:59 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/miniRT.h"

int	exit_win(t_win *win)
{
	(void)win;
	exit(0);
	return (0);
}

int	key_control(int key, t_win *win)
{
	if (key == 53)
		exit_win(win);
	return (0);
}
