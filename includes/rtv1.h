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
}					t_sdl;

typedef	union		u_color
{
	int				color;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_figure
{
	char			*name;
	int				radius;
	int				length;
	int				width;
	int				height;
	t_vector		o;
	float			ro_x;
	float			ro_y;
	float			ro_z;
	t_color			color;
}					t_figure;

typedef struct		s_scene
{
	t_figure		*figure;
	int				i;
	int				j;
	t_vector		cam;
	t_vector		D;
	t_vector		ray;
	t_vector		t_min;
	t_vector		t_max;
	int				Cw;
	int				Ch;
	int				Vw;
	int				Vh;
	int				d;
	float			k1;
	float			k2;
	float			k3;
	float			dicr;
	t_vector		oc;
}					t_scene;

void				struct_init(t_scene *sc);
void				sphere(t_figure *f);
void				cylinder(t_figure *f);
void				cone(t_figure *f);
void				plane(t_figure *f);
void				render(t_scene *sc, t_sdl *s);
void				putpixel(t_sdl *s, int x, int y, uint32_t pixel);
void				canvtoview(t_scene *sc);
void				intersect(t_scene *sc);

#endif
