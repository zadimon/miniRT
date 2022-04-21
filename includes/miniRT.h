/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:46:15 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/21 18:44:14 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT 1080
# define WIDTH 1920
# define BG_COLOR 0x75BBFD
# define DIFF_COEF 2
# define SPEC_COEF 4
# define SHADOW_COEF -30
# define SELECT_COEF 30
# define REFLECTION_COEF 0.4
# define RECURSION_DEPTH 5

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_type;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}			t_vec;

typedef struct s_amb
{
	float	amb_ratio;
	t_rgb	*amb_rgb;
}			t_amb;

typedef struct s_cam
{
	t_vec	*cam_coor;
	t_vec	*cam_vec;
	int		fov;
}			t_cam;

typedef struct s_lig
{
	t_vec	*lig_coor;
	float	brig;
	t_rgb	*lig_rgb;
}			t_lig;

typedef struct s_sp
{
	t_vec		*sp_coor;
	float		sp_r;
}				t_sp;

typedef struct s_pl
{
	t_vec		*pl_coor;
	t_vec		*pl_vec;
}				t_pl;

typedef struct s_cy
{
	t_vec		*cy_coor;
	t_vec		*cy_vec;
	float		cy_r;
	float		cy_hei;
}				t_cy;

typedef struct s_fig
{
	int				is_check;
	t_type			type;
	void			*obj;
	t_rgb			*rgb;
	struct s_fig	*next;
}					t_fig;		

typedef struct s_sc
{
	t_amb	*amb;
	t_cam	*cam;
	t_lig	*lig;
	t_fig	*fig;
}			t_sc;

typedef struct s_vport
{
	float	x;
	float	y;
	float	w_vport;
	float	x_pixel;
	float	y_pixel;
}			t_vport;

typedef struct s_look_at
{
	t_vec	right;
	t_vec	up;
	t_vec	camera;
	t_vec	or;
}			t_look_at;

typedef struct s_ray
{
	t_vec	v_o;
	t_vec	v_d;
	t_fig	*closest_fig;
	float	t_max;
	float	t_min;
}			t_ray;

typedef struct s_to_lig
{
	t_vec	v_p;
	t_vec	v_n;
	t_vec	v_v;
	t_vec	v_l;
}			t_to_lig;

typedef struct s_equ
{
	float	a;
	float	b;
	float	c;
	float	t1;
	float	t2;
}			t_equ;

typedef struct s_im
{
	void		*im;
	char		*data;
	int			bits;
	int			line;
	int			endian;
}				t_im;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_im	*im;
}			t_win;

/*-----parsing-----*/

void		get_elem(t_sc *sc, char *ar);
char		**ft_mod_split(char const *s);

/*-----create elem-----*/

void		create_amb(t_sc *sc, char **param);
void		create_cam(t_sc *sc, char **param);
void		create_lig(t_sc *sc, char **param);
void		create_sp(t_sc *sc, char **param);
void		create_pl(t_sc *sc, char **param);
void		create_cy(t_sc *sc, char **param);
t_rgb		*create_col(char *param);
t_vec		*create_coor(char *param);
t_vec		*create_vec(char *param);

/*-----utils-----*/

int			put_error(char *msg, char *w_case);
int			check_file_name(char *file_name);
int			count_sym(int fd);
char		*read_file(char *file_name);
void		init_null(t_sc *sc);

/*-----utils for creating elements-----*/

int			ft_isint(char c);
int			ft_isfloat(char c);
int			num_is_int(char *num);
int			num_is_float(char *num);

/*-----ft_atof-----*/

float		ft_atof(char *s);
int			ft_mod_atoi(const char *s);

/*-----free-----*/

void		ft_free_param(t_sc *sc);
void		ft_free_str_ar(char **ar);

/*-----rendering-----*/

void		rendering(t_sc *sc, t_vport *vport);
int			compute_light(t_sc *sc, t_ray *ray, int r);
t_vec		get_normal(t_vec v_p, t_ray *ray);
int			check_intersections(t_sc *sc, t_ray *ray);
int			get_color(t_sc *sc, t_ray *ray, int r);

/*-----camera-----*/

void		init_vport(t_sc *sc, t_vport *vport);
t_look_at	*get_look_at_matrix(t_sc *sc);
t_ray		get_ray(t_look_at *look_at, t_vport *vport);

/*-----actions on vectors-----*/

t_vec		new_vec(float x, float y, float z);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_add(t_vec v1, t_vec v2);
float		vec_len(t_vec *vec);
void		norm_vec(t_vec *vec);
float		scal_mul(t_vec v1, t_vec v2);
t_vec		mul_on_num(t_vec v, float n);
t_vec		vec_mul(t_vec v1, t_vec v2);
t_vec		matrix_mul(t_look_at *look_at, t_vec v);

/*-----color-----*/

int			create_rgb(int r, int g, int b);
void		my_mlx_pixel_put(t_im *im, int x, int y, int color);
int			get_color_with_brig(t_sc *sc, t_ray *ray, t_to_lig to_lig);
int			rgb(int color, char level);
int			add_color(int color, float coef);
int			add_color3(int c1, int c2, int c3);
int			mul_color(t_rgb col, float coef);
int			mul_int_color(int color1, float coef);
int			add_color2(int c1, int c2);

/*-----quadratic equations-----*/

t_equ		equ_for_sp(t_sp *sp, t_ray *ray);
t_equ		equ_for_cy(t_cy *cy, t_ray *ray, t_vec v_cy);
int			solve_quad_equ(t_equ *equ);
int			check_height(t_cy *cy, t_ray *ray, t_vec v_cy, t_equ *equ);

/*-----key control-----*/

int			key_control(int key, t_win *win);
int			exit_win(t_win *win);

#endif
