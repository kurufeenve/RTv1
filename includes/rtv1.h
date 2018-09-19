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
	SDL_Window	*win;
	SDL_Event	event;
	int			quit;
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
	int				x;
	int				y;
	int				z;
	int				ro_x;
	int				ro_y;
	int				ro_z;
	t_color			color;
}					t_figure;

typedef struct		s_scene
{
	char			*filename;
	int				fd;
	t_figure		*figure;
	char			*line;
	char			*str;
	char			*buff;
	int				ob;
	int				cb;
}					t_scene;

void				ft_parse(t_scene *sc);
void				read_scene(t_scene *sc);
void				struct_init(t_scene *sc);

#endif
