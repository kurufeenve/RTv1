/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:30:54 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/22 15:30:57 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	render(t_scene *sc, t_sdl *s)
{
	sc->i = -sc->Cw/2;
	while (sc->i < sc->Cw/2)
	{
		sc->j = -sc->Ch/2;
		while (sc->j < sc->Ch/2)
		{
			intersect(sc);
			sc->i += sc->Cw/2;
			sc->j += sc->Ch/2;
			//printf("sc->i = %d, sc->j = %d\n", sc->i, sc->j);
			putpixel(s, sc->i, sc->j, 0xffffff);
			sc->i -= sc->Cw/2;
			sc->j -= sc->Ch/2;
			sc->j++;
		}
		sc->i++;
	}
	printf("sc->oc.x = %f, sc->oc.y = %f, sc->oc.z = %f\n", sc->oc.x, sc->oc.y, sc->oc.z);
}

void	canvtoview(t_scene *sc)
{
	sc->D.x = sc->Vw / sc->Cw;
	sc->D.y = sc->Vh / sc->Ch;
	sc->D.z = sc->d;
}

void	intersect(t_scene *sc)
{
	// sc->oc.x = sc->cam.x - sc->figure[0].x;
	// sc->oc.y = sc->cam.y - sc->figure[0].y;
	// sc->oc.z = sc->cam.z - sc->figure[0].z;
	ft_vec_sub(sc->cam, sc->figure[0].o, &sc->oc);
}

// void	traceray(t_scene *sc)
// {

// }
