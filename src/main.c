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
	t_sdl	s;
	t_scene	sc;

	if (argc != 2)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	struct_init(&sc);
	sc.filename = argv[1];
	ft_parse(&sc);
	s.quit = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Failed to initialise EVERYTHING module.\n%s\n", SDL_GetError());
		exit(-1);
	}
	else
		printf("EVERYTHING was initialised.\n");
	atexit(SDL_Quit);

	

	// printf("Initialize the window in a 640x480.\n");
	// s.win = SDL_CreateWindow("K U R W A", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	// if (s.win == NULL)
	// {
	// 	printf("Couldn't create a fucking window, kurwa!: %s\n", SDL_GetError());
	// 	exit(-1);
	// }
	// else
	// 	printf("Window was created, kurwa!\n");
	// while (!s.quit)
	// {
	// 	while (SDL_PollEvent(&s.event))
	// 	{
	// 		if (s.event.key.keysym.scancode == 41)
	// 		{
	// 			s.quit = 1;
	// 			break;
	// 		}
	// 		if (s.event.type == SDL_WINDOWEVENT)
	// 			if (s.event.window.event == SDL_WINDOWEVENT_CLOSE)
	// 			{
	// 				s.quit = 1;
	// 				break;
	// 			}
	// 	}
	// }
	system("leaks rtv1");
	return (0);
}
