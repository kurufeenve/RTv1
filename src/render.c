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
	sc->i = -sc->cw / 2;
	while (sc->i < sc->cw / 2)
	{
		sc->j = -sc->ch / 2;
		while (sc->j < sc->ch / 2)
		{
			canvtoview(sc);
			traceray(sc);
			sc->i += sc->cw / 2;
			sc->j += sc->ch / 2;
			putpixel(s, sc->i, sc->j, sc->color.color);
			sc->i -= sc->cw / 2;
			sc->j -= sc->ch / 2;
			sc->j++;
		}
		sc->i++;
	}
}

void	canvtoview(t_scene *sc)
{
	sc->dd.x = (float)sc->i * (float)sc->vw / (float)sc->cw;
	sc->dd.y = (float)sc->j * (float)sc->vh / (float)sc->ch;
	sc->dd.z = (float)sc->d;
	camera_rotation(&sc->dd, sc->cam.ro);
}

void	camera_rotation(t_vector *n, t_vector ro)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;

	tmpx = n->x;
	tmpy = n->y;
	tmpz = n->z;
	n->x = tmpx * cos(ro.y) * cos(ro.z) + tmpz * sin(ro.y) -
	tmpy * cos(ro.y) * sin(ro.z);
	n->y = -tmpz * cos(ro.y) * sin(ro.x) + tmpx * (cos(ro.z) *
	sin(ro.x) * sin(ro.y) + cos(ro.x) * sin(ro.z)) + tmpy * (cos(ro.x) *
	cos(ro.z) - sin(ro.x) * sin(ro.y) * sin(ro.z));
	n->z = tmpz * cos(ro.x) * cos(ro.y) + tmpx * (sin(ro.x) *
	sin(ro.z) - cos(ro.x) * cos(ro.z) * sin(ro.y)) + tmpy * (cos(ro.z) *
	sin(ro.x) + cos(ro.x) * sin(ro.y) * sin(ro.z));
}

void	intersect_sph(t_scene *sc)
{
	sc->k1 = sc->dd.x * sc->dd.x + sc->dd.y * sc->dd.y + sc->dd.z * sc->dd.z;
	sc->k2 = 2 * (sc->oc.x * sc->dd.x + sc->oc.y * sc->dd.y +
	sc->oc.z * sc->dd.z);
	sc->k3 = sc->oc.x * sc->oc.x + sc->oc.y * sc->oc.y + sc->oc.z * sc->oc.z -
	sc->figure[sc->m].radius * sc->figure[sc->m].radius;
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

void	intersect_plane(t_scene *sc)
{
	float	buff;

	buff = (sc->dd.x * sc->figure[sc->m].n.x + sc->dd.y * sc->figure[sc->m].n.y
	+ sc->dd.z * sc->figure[sc->m].n.z);
	if (buff != 0)
		sc->t1 = -(sc->oc.x * sc->figure[sc->m].n.x + sc->oc.y *
		sc->figure[sc->m].n.y + sc->oc.z * sc->figure[sc->m].n.z) / buff;
	else
		sc->t1 = 0;
	sc->t2 = sc->t1;
}
