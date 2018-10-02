/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:02:08 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/30 15:02:11 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	intersect_cyl(t_scene *sc)
{
	sc->k1 = (sc->dd.x * sc->dd.x + sc->dd.y * sc->dd.y + sc->dd.z * sc->dd.z)
	- ((sc->dd.x * sc->figure[sc->m].n.x + sc->dd.y * sc->figure[sc->m].n.y +
	sc->dd.z * sc->figure[sc->m].n.z) * (sc->dd.x * sc->figure[sc->m].n.x +
	sc->dd.y * sc->figure[sc->m].n.y + sc->dd.z * sc->figure[sc->m].n.z));
	sc->k2 = 2 * ((sc->dd.x * sc->oc.x + sc->dd.y * sc->oc.y + sc->dd.z *
	sc->oc.z) - ((sc->dd.x * sc->figure[sc->m].n.x + sc->dd.y *
	sc->figure[sc->m].n.y + sc->dd.z * sc->figure[sc->m].n.z) * (sc->oc.x *
	sc->figure[sc->m].n.x + sc->oc.y * sc->figure[sc->m].n.y + sc->oc.z *
	sc->figure[sc->m].n.z)));
	sc->k3 = (sc->oc.x * sc->oc.x + sc->oc.y * sc->oc.y + sc->oc.z *
	sc->oc.z) - ((sc->oc.x * sc->figure[sc->m].n.x + sc->oc.y *
	sc->figure[sc->m].n.y + sc->oc.z * sc->figure[sc->m].n.z) * (sc->oc.x *
	sc->figure[sc->m].n.x + sc->oc.y * sc->figure[sc->m].n.y + sc->oc.z *
	sc->figure[sc->m].n.z)) - sc->figure[sc->m].radius *
	sc->figure[sc->m].radius;
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

void	intersect_cone(t_scene *sc)
{
	sc->figure[sc->m].k = (float)tan(sc->figure[sc->m].angl);
	sc->k1 = (sc->dd.x * sc->dd.x + sc->dd.y * sc->dd.y + sc->dd.z * sc->dd.z) -
	(1 + sc->figure[sc->m].k * sc->figure[sc->m].k) * (sc->dd.x *
	sc->figure[sc->m].n.x + sc->dd.y * sc->figure[sc->m].n.y +
	sc->dd.z * sc->figure[sc->m].n.z) * (sc->dd.x * sc->figure[sc->m].n.x +
	sc->dd.y * sc->figure[sc->m].n.y + sc->dd.z * sc->figure[sc->m].n.z);
	sc->k2 = 2 * ((sc->dd.x * sc->oc.x + sc->dd.y * sc->oc.y + sc->dd.z *
	sc->oc.z) - (1 + sc->figure[sc->m].k * sc->figure[sc->m].k) * ((sc->dd.x *
	sc->figure[sc->m].n.x + sc->dd.y * sc->figure[sc->m].n.y + sc->dd.z *
	sc->figure[sc->m].n.z) * (sc->oc.x * sc->figure[sc->m].n.x + sc->oc.y *
	sc->figure[sc->m].n.y + sc->oc.z * sc->figure[sc->m].n.z)));
	sc->k3 = (sc->oc.x * sc->oc.x + sc->oc.y * sc->oc.y + sc->oc.z *
	sc->oc.z) - (1 + sc->figure[sc->m].k * sc->figure[sc->m].k) * ((sc->oc.x *
	sc->figure[sc->m].n.x + sc->oc.y * sc->figure[sc->m].n.y + sc->oc.z *
	sc->figure[sc->m].n.z) * (sc->oc.x * sc->figure[sc->m].n.x + sc->oc.y *
	sc->figure[sc->m].n.y + sc->oc.z * sc->figure[sc->m].n.z));
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
	sc->m = 0;
	sc->closfig = -1;
	sc->clost = sc->eov;
	while (sc->m < sc->pa.nof)
	{
		ft_vec_sub(sc->cam.o, sc->figure[sc->m].o, &sc->oc);
		intersection(sc);
	}
	sc->p.x = sc->cam.o.x + sc->clost * sc->dd.x;
	sc->p.y = sc->cam.o.y + sc->clost * sc->dd.y;
	sc->p.z = sc->cam.o.z + sc->clost * sc->dd.z;
	if (sc->figure[sc->closfig].type == 0)
		normal_sph(sc);
	if (sc->figure[sc->closfig].type == 3)
		normal_plane(sc);
	if (sc->figure[sc->closfig].type == 2)
		normal_cone(sc);
	if (sc->figure[sc->closfig].type == 1)
		normal_cyl(sc);
	if (sc->clost > 1)
		lighting(sc);
	sc->color.channel[0] *= sc->intensity;
	sc->color.channel[1] *= sc->intensity;
	sc->color.channel[2] *= sc->intensity;
}

void	normal_plane(t_scene *sc)
{
	sc->n.x = sc->figure[sc->closfig].n.x;
	sc->n.y = sc->figure[sc->closfig].n.y;
	sc->n.z = sc->figure[sc->closfig].n.z;
	sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y + sc->n.z *
	sc->n.z);
	if (sc->n.length != 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
}

void	normal_cone(t_scene *sc)
{
	sc->mm = (sc->dd.x * sc->figure[sc->closfig].n.x +
	sc->dd.y * sc->figure[sc->closfig].n.y + sc->dd.z *
	sc->figure[sc->closfig].n.z) * sc->clost + (sc->oc.x *
	sc->figure[sc->closfig].n.x + sc->oc.y * sc->figure[sc->closfig].n.y +
	sc->oc.z * sc->figure[sc->closfig].n.z);
	sc->n.x = sc->p.x - sc->figure[sc->closfig].o.x - (1 +
	sc->figure[sc->closfig].k * sc->figure[sc->closfig].k) *
	(sc->figure[sc->closfig].n.x * sc->mm);
	sc->n.y = sc->p.y - sc->figure[sc->closfig].o.y - (1 +
	sc->figure[sc->closfig].k * sc->figure[sc->closfig].k) *
	(sc->figure[sc->closfig].n.y * sc->mm);
	sc->n.z = sc->p.z - sc->figure[sc->closfig].o.z - (1 +
	sc->figure[sc->closfig].k * sc->figure[sc->closfig].k) *
	(sc->figure[sc->closfig].n.z * sc->mm);
	sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y + sc->n.z *
	sc->n.z);
	if (sc->n.length != 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
}
