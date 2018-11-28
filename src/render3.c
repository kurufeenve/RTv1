/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:03:32 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/30 15:03:33 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	normal_cyl(t_scene *sc)
{
	sc->mm = (sc->dd.x * sc->figure[sc->closfig].n.x +
	sc->dd.y * sc->figure[sc->closfig].n.y + sc->dd.z *
	sc->figure[sc->closfig].n.z) * sc->clost + (sc->oc.x *
	sc->figure[sc->closfig].n.x + sc->oc.y * sc->figure[sc->closfig].n.y +
	sc->oc.z * sc->figure[sc->closfig].n.z);
	sc->n.x = sc->p.x - sc->figure[sc->closfig].o.x -
	(sc->figure[sc->closfig].n.x * sc->mm);
	sc->n.y = sc->p.y - sc->figure[sc->closfig].o.y -
	(sc->figure[sc->closfig].n.y * sc->mm);
	sc->n.z = sc->p.z - sc->figure[sc->closfig].o.z -
	(sc->figure[sc->closfig].n.z * sc->mm);
	sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y + sc->n.z *
	sc->n.z);
	if (sc->n.length != 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
}

void	normal_sph(t_scene *sc)
{
	sc->n.x = sc->p.x - sc->figure[sc->closfig].o.x;
	sc->n.y = sc->p.y - sc->figure[sc->closfig].o.y;
	sc->n.z = sc->p.z - sc->figure[sc->closfig].o.z;
	sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y +
	sc->n.z * sc->n.z);
	if (sc->n.length != 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
}

void	lighting(t_scene *sc)
{
	sc->intensity = 0.05;
	sc->l.x = sc->p_l.o.x - sc->p.x;
	sc->l.y = sc->p_l.o.y - sc->p.y;
	sc->l.z = sc->p_l.o.z - sc->p.z;
	sc->n_dot_l = sc->n.x * sc->l.x + sc->n.y * sc->l.y + sc->n.z * sc->l.z;
	if (sc->n_dot_l > 0)
		sc->intensity += sc->p_l.intensity * sc->n_dot_l / (sqrt(sc->n.x *
		sc->n.x + sc->n.y * sc->n.y + sc->n.z * sc->n.z) * sqrt(sc->l.x *
		sc->l.x + sc->l.y * sc->l.y + sc->l.z * sc->l.z));
}

void	intersection(t_scene *sc)
{
	if (sc->figure[sc->m].type == 0)
		intersect_sph(sc);
	if (sc->figure[sc->m].type == 3)
		intersect_plane(sc);
	if (sc->figure[sc->m].type == 1)
		intersect_cyl(sc);
	if (sc->figure[sc->m].type == 2)
		intersect_cone(sc);
	if (sc->t1 > 1 && sc->t1 < sc->clost)
	{
		sc->clost = sc->t1;
		sc->closfig = sc->m;
	}
	if (sc->t2 > 1 && sc->t2 < sc->clost)
	{
		sc->clost = sc->t2;
		sc->closfig = sc->m;
	}
	if (sc->closfig > -1 || sc->clost != sc->eov)
		sc->color.color = sc->figure[sc->closfig].color.color;
	if (sc->closfig == -1)
		sc->color.color = 0x000000;

	sc->p.x = sc->cam.o.x + sc->clost * sc->dd.x;
	sc->p.y = sc->cam.o.y + sc->clost * sc->dd.y;
	sc->p.z = sc->cam.o.z + sc->clost * sc->dd.z;

	// if (sc->i == 0 && sc->j == -100)
	// {
	// 	printf("P %f, %f, %f\n", sc->p.x, sc->p.y, sc->p.z);
	// 	printf("O %f, %f, %f\n", sc->figure[sc->closfig].o.x, sc->figure[sc->closfig].o.y, sc->figure[sc->closfig].o.z);
	// 	printf("PC %f, %f, %f\n", sc->figure[sc->closfig].pc.x, sc->figure[sc->closfig].pc.y, sc->figure[sc->closfig].pc.z);
	// 	printf("V %f, %f, %f\n", sc->figure[sc->closfig].n.x, sc->figure[sc->closfig].n.y, sc->figure[sc->closfig].n.z);
	// 	printf("m = %f\n", sc->figure[sc->closfig].m_figure_length);
	// }
	
}
