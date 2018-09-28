/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:05:32 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/27 17:05:34 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	camera_move_x(t_sdl *s, t_scene *sc)
{
	if (s->event.key.keysym.scancode == 80 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.x--;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 79 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.x++;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
}

void	camera_move_y(t_sdl *s, t_scene *sc)
{
	if (s->event.key.keysym.scancode == 46 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.y--;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 45 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.y++;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
}

void	camera_move_z(t_sdl *s, t_scene *sc)
{
	if (s->event.key.keysym.scancode == 81 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.z--;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 82 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.o.z++;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
}

void	camera_rotate(t_sdl *s, t_scene *sc)
{
	if (s->event.key.keysym.scancode == 26 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.x += 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 22 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.x -= 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	if (s->event.key.keysym.scancode == 4 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.y -= 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 7 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.y += 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
}

void	camera_rotate_z(t_sdl *s, t_scene *sc)
{
	if (s->event.key.keysym.scancode == 20 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.z -= 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
	else if (s->event.key.keysym.scancode == 8 && s->event.type == SDL_KEYDOWN)
	{
		sc->cam.ro.z += 0.087266462599716;
		render(sc, s);
		SDL_UpdateWindowSurface(s->win);
	}
}
