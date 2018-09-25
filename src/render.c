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
			canvtoview(sc);
			//printf("sc->D.x = %f, sc->D.y = %f, sc->D.z = %f\n", sc->D.x, sc->D.y, sc->D.z);
			//intersect(sc);
			traceray(sc);
			sc->i += sc->Cw/2;
			sc->j += sc->Ch/2;
			//printf("sc->i = %d, sc->j = %d\n", sc->i, sc->j);
			putpixel(s, sc->i, sc->j, sc->color.color);
			sc->i -= sc->Cw/2;
			sc->j -= sc->Ch/2;
			sc->j++;
		}
		sc->i++;
	}
	//printf("sc->oc.x = %f, sc->oc.y = %f, sc->oc.z = %f\n", sc->oc.x, sc->oc.y, sc->oc.z);
}

void	canvtoview(t_scene *sc)
{
	sc->D.x = (float)sc->i * (float)sc->Vw / (float)sc->Cw;
	sc->D.y = (float)sc->j * (float)sc->Vh / (float)sc->Ch;
	sc->D.z = (float)sc->d;
}

void	intersect(t_scene *sc)
{
	ft_vec_sub(sc->cam, sc->figure[0].o, &sc->oc);
	sc->k1 = sc->D.x * sc->D.x + sc->D.y * sc->D.y + sc->D.z * sc->D.z;
	sc->k2 = 2 * (sc->oc.x * sc->D.x + sc->oc.y * sc->D.y +
	sc->oc.z * sc->D.z);
	sc->k3 = sc->oc.x * sc->oc.x + sc->oc.y * sc->oc.y + sc->oc.z * sc->oc.z -
	sc->figure[0].radius * sc->figure[0].radius;
	sc->discr = sc->k2 * sc->k2 - 4 * sc->k1 * sc->k3;
	if (sc->discr < 0)
	{
		sc->t1 = 0;
		sc->t2 = 0;
		return ;
	}
	sc->t1 = (-sc->k2 + sqrtf(sc->discr)) / (2 * sc->k1);
	sc->t2 = (-sc->k2 - sqrtf(sc->discr)) / (2 * sc->k1);
}

void	traceray(t_scene *sc)
{
	intersect(sc);
	sc->clost = 1;
	// if (sc->t1 > 1 && sc->t1 < sc->clost)
	// 	sc->clost = sc->t1;
	// if (sc->t2 > 1 && sc->t2 < sc->clost)
	// 	sc->clost = sc->t2;
	//printf("sc->t1 = %f, sc->t2 = %f\n", sc->t1, sc->t2);
	if (sc->t1 > 1 || sc->t2 > 1)
		sc->color.color = sc->figure[0].color.color;
	else
		sc->color.color = 0x000000;
}
