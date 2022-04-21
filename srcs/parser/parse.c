/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:00:17 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 20:00:20 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	choose_type(t_sc *sc, char **param)
{
	if (!ft_strcmp(param[0], "A"))
		create_amb(sc, param);
	else if (!ft_strcmp(param[0], "C"))
		create_cam(sc, param);
	else if (!ft_strcmp(param[0], "L"))
		create_lig(sc, param);
	else if (!ft_strcmp(param[0], "sp"))
		create_sp(sc, param);
	else if (!ft_strcmp(param[0], "pl"))
		create_pl(sc, param);
	else if (!ft_strcmp(param[0], "cy"))
		create_cy(sc, param);
	else
		exit(put_error("Invalid identifier: ", param[0]));
}

void	get_elem(t_sc *sc, char *ar)
{
	char	**param;

	param = ft_mod_split(ar);
	if (param[0])
		choose_type(sc, param);
	ft_free_str_ar(param);
}
