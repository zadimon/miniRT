/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_req_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:17:05 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 19:07:41 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	create_lig(t_sc *sc, char **param)
{
	int	i;

	if (sc->lig)
		exit(put_error("Repeating identifier: ", "L"));
	sc->lig = malloc(sizeof(t_lig));
	if (!(sc->lig))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		exit(put_error("Invalid amount of light parameters", NULL));
	sc->lig->lig_coor = create_coor(param[1]);
	if (!num_is_float(param[2]))
		exit(put_error("Invalid brightness: ", param[2]));
	sc->lig->brig = ft_atof(param[2]);
	if (sc->lig->brig < 0.0 || sc->lig->brig > 1.0)
		exit(put_error("Brightness is out of range: ", param[2]));
	sc->lig->lig_rgb = create_col(param[3]);
}

void	create_cam(t_sc *sc, char **param)
{
	int	i;

	if (sc->cam)
		exit(put_error("Repeating identifier: ", "C"));
	sc->cam = malloc(sizeof(t_cam));
	if (!(sc->cam))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		exit(put_error("Invalid amount of camera parameters", NULL));
	sc->cam->cam_coor = create_coor(param[1]);
	sc->cam->cam_vec = create_vec(param[2]);
	if (!num_is_int(param[3]))
		exit(put_error("Invalid FOV: ", param[3]));
	sc->cam->fov = ft_mod_atoi(param[3]);
	if (sc->cam->fov < 0 || sc->cam->fov > 180)
		exit(put_error("FOV is out of range: ", param[3]));
}

void	create_amb(t_sc *sc, char **param)
{
	int	i;

	if (sc->amb)
		exit(put_error("Repeating identifier: ", "A"));
	sc->amb = malloc(sizeof(t_amb));
	if (!(sc->amb))
		exit(put_error("Malloc error", NULL));
	i = 0;
	while (param[i])
		i++;
	if (i != 3)
		exit(put_error("Invalid amount of ambient parameters", NULL));
	if (!num_is_float(param[1]))
		exit(put_error("Invalid ambient lighting ratio: ", param[1]));
	sc->amb->amb_ratio = ft_atof(param[1]);
	if (sc->amb->amb_ratio < 0.0 || sc->amb->amb_ratio > 1.0)
		exit(put_error("Ambient lighting ratio is out of range: ", param[1]));
	sc->amb->amb_rgb = create_col(param[2]);
}
