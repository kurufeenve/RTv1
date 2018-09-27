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

int		main(int argc, char **argv)
{
	//t_sdl	s;
	t_scene	sc;

	if (argc != 2)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	struct_init(&sc);
	sc.filename = argv[1];
	ft_parse(&sc);
	// ft_sdl_init(&s, &sc);
	// render(&sc, &s);
	// SDL_UpdateWindowSurface(s.win);
	// while (!s.quit)
	// {
	// 	key_hook(&s, &sc);
	// }
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

// void	key_hook(t_sdl *s, t_scene *sc)
// {
// 	while (SDL_PollEvent(&s->event))
// 	{
// 		if (s->event.key.keysym.scancode == 41)
// 		{
// 			s->quit = 1;
// 			break ;
// 		}
// 		camera_move_y(s, sc);
// 		camera_move_z(s, sc);
// 		camera_move_x(s, sc);
// 		camera_rotate(s, sc);
// 		// if (s.event.type == SDL_KEYUP)
// 		// 	break ;
// 		if (s->event.type == SDL_WINDOWEVENT)
// 			if (s->event.window.event == SDL_WINDOWEVENT_CLOSE)
// 			{
// 				s->quit = 1;
// 				break ;
// 			}
// 	}
// }

// void	ft_sdl_init(t_sdl *s, t_scene *sc)
// {
// 	s->error = NULL;
// 	s->quit = 0;
// 	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
// 	{
// 		ft_putstr("Failed to initialise EVERYTHING module.\n");
// 		if ((s->error = (char *)SDL_GetError()))
// 			ft_putstr(s->error);
// 		system("leaks RTv1");
// 		exit(-1);
// 	}
// 	else
// 		ft_putstr("EVERYTHING was initialised.\n");
// 	atexit(SDL_Quit);
// 	s->win = SDL_CreateWindow("RTv1",
// 		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sc->cw, sc->ch, 0);
// 	if (s->win == NULL)
// 	{
// 		if ((s->error = (char *)SDL_GetError()))
// 			ft_putstr(s->error);
// 		system("leaks RTv1");
// 		exit(-1);
// 	}
// 	s->surface = SDL_GetWindowSurface(s->win);
// 	SDL_memset(s->surface->pixels, 0, s->surface->h * s->surface->pitch);
// }
