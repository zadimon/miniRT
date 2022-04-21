/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:35:02 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 18:44:10 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_to_lig	get_ray_to_lig(t_sc *sc, t_ray *ray)
{
	t_to_lig	to_lig;

	to_lig.v_p = vec_add(ray->v_o,
			mul_on_num(ray->v_d, ray->t_max));
	to_lig.v_n = get_normal(to_lig.v_p, ray);
	to_lig.v_v = mul_on_num(ray->v_d, -1);
	to_lig.v_l = vec_sub(*sc->lig->lig_coor, to_lig.v_p);
	norm_vec(&to_lig.v_l);
	return (to_lig);
}

int	compute_light(t_sc *sc, t_ray *ray, int r)
{
	int				color;
	int				refl_color;
	t_ray			refl_ray;
	t_to_lig		to_lig;

	to_lig = get_ray_to_lig(sc, ray);
	color = get_color_with_brig(sc, ray, to_lig);
	if (r <= 0 )
		return (color);
	refl_ray.v_o = to_lig.v_p;
	refl_ray.v_d = vec_sub(mul_on_num(to_lig.v_n,
				2 * scal_mul(to_lig.v_n, to_lig.v_v)), to_lig.v_v);
	refl_ray.t_min = 0.1;
	refl_ray.t_max = MAXFLOAT;
	refl_color = get_color(sc, &refl_ray, r - 1);
	color = mul_int_color(color, REFLECTION_COEF);
	refl_color = mul_int_color(refl_color, (1 - REFLECTION_COEF));
	color = add_color2(color, refl_color);
	return (color);
}

int	get_color(t_sc *sc, t_ray *ray, int r)
{
	int		color;

	check_intersections(sc, ray);
	if (ray->closest_fig)
	{
		color = compute_light(sc, ray, r);
		return (color);
	}
	return (BG_COLOR);
}

void	start_rend(t_im *im, t_sc *sc, t_vport *vport)
{
	int			x;
	int			y;
	t_look_at	*look_at;
	t_ray		ray;
	int			color;

	look_at = get_look_at_matrix(sc);
	y = 0;
	while (y < HEIGHT)
	{
		vport->y = y;
		x = 0;
		while (x < WIDTH)
		{
			vport->x = x;
			ray = get_ray(look_at, vport);
			color = get_color(sc, &ray, RECURSION_DEPTH);
			my_mlx_pixel_put(im, x, y, color);
			x++;
		}
		y++;
	}
	free(look_at);
}

void	rendering(t_sc *sc, t_vport *vport)
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx,
			WIDTH, HEIGHT, "miniRT");
	win.im = malloc(sizeof(t_im));
	win.im->im = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	win.im->data = mlx_get_data_addr(win.im->im,
			&(win.im->bits), &(win.im->line),
			&(win.im->endian));
	start_rend(win.im, sc, vport);
	mlx_hook(win.win, 2, 0, key_control, &win);
	mlx_hook(win.win, 17, 0, exit_win, &win);
	mlx_put_image_to_window(win.mlx, win.win,
		win.im->im, 0, 0);
	mlx_loop(win.mlx);
}
