/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:58:13 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/20 23:16:18 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_rt(char *file_name, t_sc *sc)
{
	char	*s;
	char	**ar;
	int		i;

	init_null(sc);
	s = read_file(file_name);
	i = 0;
	ar = ft_split(s, '\n');
	free(s);
	while (ar[i])
	{
		get_elem(sc, ar[i]);
		free(ar[i]);
		i++;
	}
	if (!(sc->amb))
		exit(put_error("Missing identifier: ", "A"));
	if (!(sc->cam))
		exit(put_error("Missing identifier: ", "C"));
	if (!(sc->lig))
		exit(put_error("Missing identifier: ", "L"));
	free(ar);
}

void	norm_all_vec(t_sc *sc)
{
	t_fig	*tmp;
	t_pl	*pl;
	t_cy	*cy;

	norm_vec(sc->cam->cam_vec);
	tmp = sc->fig;
	while (tmp)
	{
		if (tmp->type == PLANE)
		{
			pl = (t_pl *)tmp->obj;
			norm_vec(pl->pl_vec);
		}
		if (tmp->type == CYLINDER)
		{
			cy = (t_cy *)tmp->obj;
			norm_vec(cy->cy_vec);
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_sc	sc;
	t_vport	vport;

	if (argc != 2)
		return (put_error("Invalid amount of arguments", NULL));
	if (check_file_name(argv[1]))
		return (put_error("Invalid file name", NULL));
	init_rt(argv[1], &sc);
	init_vport(&sc, &vport);
	norm_all_vec(&sc);
	rendering(&sc, &vport);
	ft_free_param(&sc);
	return (0);
}
