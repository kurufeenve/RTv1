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

int		main(void)
{
	t_sdl	s;
	t_scene	sc;

	// if (argc != 2)
	// {
	// 	printf("wrong number of arguments.\n");
	// 	exit(0);
	// }
	struct_init(&sc);
	//sc.filename = argv[1];	
	s.quit = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Failed to initialise EVERYTHING module.\n%s\n", SDL_GetError());
		exit(-1);
	}
	else
		printf("EVERYTHING was initialised.\n");
	atexit(SDL_Quit);
	printf("Initialize the window in a 1000x1000.\n");
	s.win = SDL_CreateWindow("K U R W A", 100, 100, sc.Cw, sc.Ch, SDL_WINDOW_SHOWN);
	if (s.win == NULL)
	{
		printf("Couldn't create a fucking window, kurwa!: %s\n", SDL_GetError());
		exit(-1);
	}
	else
		printf("Window was created, kurwa!\n");
	s.surface = SDL_GetWindowSurface(s.win);
	int	yellow = SDL_MapRGB(s.surface->format, 0xff, 0xff, 0x00);
	printf("yellow = %x\n", yellow);
	render(&sc);
	putpixel(&s, 10, 10, 0xffffff);
	while (!s.quit)
	{
		while (SDL_PollEvent(&s.event))
		{
			if (s.event.key.keysym.scancode == 41)
			{
				s.quit = 1;
				break;
			}
			if (s.event.type == SDL_WINDOWEVENT)
				if (s.event.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					s.quit = 1;
					break;
				}
		}
	}
	system("leaks RTv1");
	return (0);
}

void	putpixel(t_sdl *s, int x, int y, uint32_t pixel)
{
	s->bpp = s->surface->format->BytesPerPixel;
	s->p = (uint32_t *)s->surface->pixels + y * s->surface->pitch + x * s->bpp;
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
