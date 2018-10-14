/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:54:49 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/14 15:54:50 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <SDL2/SDL.h>

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		*surface;
	int				bpp;
	uint32_t		*p;
	int				quit;
	char			*error;
}					t_sdl;

typedef	union		u_color
{
	int				color;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_light
{
	t_vector		o;
	float			intensity;
}					t_light;

typedef struct		s_camera
{
	t_vector		o;
	t_vector		ro;
}					t_camera;

typedef struct		s_figure
{
	int				type;
	int				radius;
	float			angl;
	float			k;
	t_vector		o;
	t_vector		n;
	t_vector		a;
	t_color			color;
}					t_figure;

typedef struct		s_parse
{
	int				fd;
	char			*filename;
	char			*str;
	int				boo;
	int				prev_type;
	int				index;
	int				index2;
	char			*buff;
	char			*f_buff;
	int				type;
	int				nof;
	char			*line;
}					t_parse;

typedef struct		s_scene
{
	t_parse			pa;
	t_figure		*figure;
	int				i;
	int				j;
	int				m;
	t_camera		cam;
	t_vector		dd;
	t_vector		ray;
	float			t1;
	float			t2;
	int				cw;
	int				ch;
	int				vw;
	int				vh;
	int				d;
	float			k1;
	float			k2;
	float			k3;
	float			discr;
	t_vector		oc;
	float			clost;
	float			eov;
	int				closfig;
	t_color			color;
	t_light			p_l;
	t_vector		p;
	t_vector		n;
	t_vector		l;
	float			cosa;
	float			n_dot_l;
	float			intensity;
	float			mm;
}					t_scene;

/*
**parser
*/

void				ft_parse(t_scene *sc);
void				validation(t_scene *sc);
void				parse_fig(t_scene *sc);
void				read_scene(t_scene *sc);
void				read_figures(t_scene *sc);
void				count_figures(t_scene *sc);
void				read_sphere(t_scene *sc);
void				read_cylinder(t_scene *sc);
void				read_cone(t_scene *sc);
void				read_plane(t_scene *sc);
void				read_light(t_scene *sc);
void				read_camera(t_scene *sc);
void				read_radius(t_scene *sc);
void				read_angle(t_scene *sc);
void				read_o_vector(t_scene *sc);
void				read_n_vector(t_scene *sc);
void				read_a_figure(t_scene *sc);
void				figure_rotation(t_vector *n, t_vector a);
void				read_color(t_scene *sc);
void				read_intensity(t_scene *sc);
void				read_o_light(t_scene *sc);
void				read_a_camera(t_scene *sc);
void				normalisation(t_vector *v);

/*
**SDL
*/

void				putpixel(t_sdl *s, int x, int y, uint32_t pixel);
void				canvtoview(t_scene *sc);
void				key_hook(t_sdl *s, t_scene *sc);
void				ft_sdl_init(t_sdl *s, t_scene *sc);

/*
**Camera
*/

void				camera_rotation(t_vector *n, t_vector ro);
void				camera_move_x(t_sdl *s, t_scene *sc);
void				camera_move_y(t_sdl *s, t_scene *sc);
void				camera_move_z(t_sdl *s, t_scene *sc);
void				camera_rotate(t_sdl *s, t_scene *sc);
void				camera_rotate_z(t_sdl *s, t_scene *sc);

/*
**Render
*/

void				intersect_sph(t_scene *sc);
void				traceray(t_scene *sc);
void				lighting(t_scene *sc);
void				intersect_cyl(t_scene *sc);
void				intersect_plane(t_scene *sc);
void				intersect_cone(t_scene *sc);
void				intersection(t_scene *sc);
void				normal_sph(t_scene *sc);
void				normal_plane(t_scene *sc);
void				normal_cone(t_scene *sc);
void				normal_cyl(t_scene *sc);
void				render(t_scene *sc, t_sdl *s);

/*
**initialisation and error management
*/

void				errors(int	n);
void				struct_init(t_scene *sc);

#endif
