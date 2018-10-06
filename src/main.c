/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:53:02 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/14 15:53:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
potential bugs:
angle - degree to radian convertion multiple times through the code. check = 0;

*/

int		main(int argc, char **argv)
{
	t_sdl	s;
	t_scene	sc;

	if (argc != 2)
		errors(0);
	struct_init(&sc);
	sc.pa.filename = argv[1];
	ft_parse(&sc);
	printf("type = %d, radius = %d, x = %f, y = %f, z = %f, color = %x\n", sc.figure[0].type,
	sc.figure[0].radius, sc.figure[0].o.x, sc.figure[0].o.y, sc.figure[0].o.z, sc.figure[0].color.color);
	printf("type = %d, radius = %d, x = %f, y = %f, z = %f, color = %x\n", sc.figure[1].type,
	sc.figure[1].radius, sc.figure[1].o.x, sc.figure[1].o.y, sc.figure[1].o.z, sc.figure[1].color.color);
	printf("type = %d, ox = %f, oy = %f, oz = %f, nx = %f, ny = %f, nz = %f, color = %x\n",
	sc.figure[2].type, sc.figure[2].o.x, sc.figure[2].o.y, sc.figure[2].o.z, sc.figure[2].o.x,
	sc.figure[2].o.y, sc.figure[2].o.z, sc.figure[2].color.color);
	printf("type = %d, radius = %d, ox = %f, oy = %f, oz = %f, nx = %f, ny = %f, nz = %f, color = %x\n",
	sc.figure[3].type, sc.figure[3].radius, sc.figure[3].o.x, sc.figure[3].o.y, sc.figure[3].o.z,
	sc.figure[3].n.x, sc.figure[3].n.y, sc.figure[3].n.z, sc.figure[3].color.color);
	printf("type = %d, angle = %f, ox = %f, oy = %f, oz = %f, nx = %f, ny = %f, nz = %f, color = %x\n",
	sc.figure[4].type, sc.figure[4].angl, sc.figure[4].o.x, sc.figure[4].o.y, sc.figure[4].o.z,
	sc.figure[4].n.x, sc.figure[4].n.y, sc.figure[4].n.z, sc.figure[4].color.color);
	ft_sdl_init(&s, &sc);
	render(&sc, &s);
	SDL_UpdateWindowSurface(s.win);
	while (!s.quit)
		key_hook(&s, &sc);
	system("leaks RTv1");
	return (0);
}

void	putpixel(t_sdl *s, int x, int y, uint32_t pixel)
{
	s->bpp = s->surface->format->BytesPerPixel;
	s->p = s->surface->pixels + y * s->surface->pitch + x * s->bpp;
	if (s->bpp == 1)
		*s->p = pixel;
	else if (s->bpp == 2)
		*s->p = pixel;
	else if (s->bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			s->p[0] = (pixel >> 16) & 0xff;
			s->p[1] = (pixel >> 8) & 0xff;
			s->p[2] = pixel & 0xff;
		}
		else
		{
			s->p[0] = pixel & 0xff;
			s->p[1] = (pixel >> 8) & 0xff;
			s->p[2] = (pixel >> 16) & 0xff;
		}
	}
	else if (s->bpp == 4)
		*s->p = pixel;
}

void	key_hook(t_sdl *s, t_scene *sc)
{
	while (SDL_PollEvent(&s->event))
	{
		if (s->event.key.keysym.scancode == 41)
		{
			s->quit = 1;
			break ;
		}
		camera_move_y(s, sc);
		camera_move_z(s, sc);
		camera_move_x(s, sc);
		camera_rotate(s, sc);
		camera_rotate_z(s, sc);
		if (s->event.type == SDL_WINDOWEVENT)
			if (s->event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				s->quit = 1;
				break ;
			}
	}
}

void	ft_sdl_init(t_sdl *s, t_scene *sc)
{
	s->error = NULL;
	s->quit = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_putstr("Failed to initialise EVERYTHING module.\n");
		if ((s->error = (char *)SDL_GetError()))
			ft_putstr(s->error);
		system("leaks RTv1");
		exit(0);
	}
	else
		ft_putstr("EVERYTHING was initialised.\n");
	atexit(SDL_Quit);
	s->win = SDL_CreateWindow("RTv1",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sc->cw, sc->ch, 0);
	if (s->win == NULL)
	{
		if ((s->error = (char *)SDL_GetError()))
			ft_putstr(s->error);
		system("leaks RTv1");
		exit(0);
	}
	s->surface = SDL_GetWindowSurface(s->win);
	SDL_memset(s->surface->pixels, 0, s->surface->h * s->surface->pitch);
}

void	errors(int	n)
{
	if (n == 0)
		ft_putstr("wront number of arguments\n");
	else if(n == 1)
		ft_putstr("wrong file extension\n");
	else if(n == 2)
		ft_putstr("\n===	!!! NOT A FILE !!!	===\n\n");
	else if(n == 3)
		ft_putstr("syntax error\n");
	else if(n == 4)
		ft_putstr("Wrong type\n");
	system("leaks RTv1");
	exit(0);
}
