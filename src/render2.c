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
	float	dot_dd_dd = ft_vec_dot(sc->dd, sc->dd);
	float	dot_dd_oc = ft_vec_dot(sc->dd, sc->oc);
	float	dot_oc_oc = ft_vec_dot(sc->oc, sc->oc);
	float	dot_dd_sc_figure_n = ft_vec_dot(sc->dd, sc->figure[sc->m].n);
	float	dot_oc_sc_figure_n = ft_vec_dot(sc->oc, sc->figure[sc->m].n);

	sc->k1 = dot_dd_dd - (dot_dd_sc_figure_n * dot_dd_sc_figure_n);
	sc->k2 = 2 * (dot_dd_oc - (dot_dd_sc_figure_n * dot_oc_sc_figure_n));
	sc->k3 = dot_oc_oc - (dot_oc_sc_figure_n * dot_oc_sc_figure_n) - sc->figure[sc->m].radius *
	sc->figure[sc->m].radius;
	sc->discr = sc->k2 * sc->k2 - 4 * sc->k1 * sc->k3;
	if (sc->discr < 0)
	{
		sc->t1 = 0;
		sc->t2 = 0;
		return ;
	}
	// if (sc->i == 0 && sc->j == 0)
	// {
	// 	printf("sc->i = %d, sc->j = %d, sc->k2 = %f, sc->discr = %f, sc->k1 = %f, sc->t1 = %f\n",
	// 	sc->i, sc->j, sc->k2, sc->discr, sc->k1, sc->t1);
	// }
	sc->t1 = (-sc->k2 + sqrtf(sc->discr)) / (2 * sc->k1);
	// if (sc->i == 0 && sc->j == 0)
	// {
	// 	printf("sc->i = %d, sc->j = %d, sc->k2 = %f, sc->discr = %f, sc->k1 = %f, sc->t1 = %f\n",
	// 	sc->i, sc->j, sc->k2, sc->discr, sc->k1, sc->t1);
	// }
	sc->t2 = (-sc->k2 - sqrtf(sc->discr)) / (2 * sc->k1);
	// printf("sc->i = %d, sc->j = %d, sc->k2 = %f, sc->discr = %f, sc->k1 = %f, sc->t1 = %f, sc->t2 = %f\n",
	// 	sc->i, sc->j, sc->k2, sc->discr, sc->k1, sc->t1, sc->t2);
	sc->figure[sc->m].p1.x = sc->cam.o.x + sc->t1 * sc->dd.x;
	sc->figure[sc->m].p1.y = sc->cam.o.y + sc->t1 * sc->dd.y;
	sc->figure[sc->m].p1.z = sc->cam.o.z + sc->t1 * sc->dd.z;

	ft_vec_sub(sc->figure[sc->m].p1, sc->figure[sc->m].o, &sc->figure[sc->m].pc);
	sc->figure[sc->m].m_figure_length = ft_vec_dot(sc->figure[sc->m].pc,
	sc->figure[sc->m].n);

	if (sc->figure[sc->m].m_figure_length <= 0 || sc->figure[sc->m].m_figure_length >= (float)sc->figure[sc->m].length)
	{
		sc->t1 = -1;
	}
	sc->figure[sc->m].p2.x = sc->cam.o.x + sc->t2 * sc->dd.x;
	sc->figure[sc->m].p2.y = sc->cam.o.y + sc->t2 * sc->dd.y;
	sc->figure[sc->m].p2.z = sc->cam.o.z + sc->t2 * sc->dd.z;

	ft_vec_sub(sc->figure[sc->m].p2, sc->figure[sc->m].o, &sc->figure[sc->m].pc);
	sc->figure[sc->m].m_figure_length = ft_vec_dot(sc->figure[sc->m].pc,
	sc->figure[sc->m].n);

	if (sc->figure[sc->m].m_figure_length <= 0 || sc->figure[sc->m].m_figure_length >= (float)sc->figure[sc->m].length)
	{
		sc->t2 = -1;
	}
}

void	intersect_cone(t_scene *sc)
{
	float	dot_dd_dd = ft_vec_dot(sc->dd, sc->dd);
	float	dot_dd_oc = ft_vec_dot(sc->dd, sc->oc);
	float	dot_oc_oc = ft_vec_dot(sc->oc, sc->oc);
	float	dot_dd_sc_figure_n = ft_vec_dot(sc->dd, sc->figure[sc->m].n);
	float	dot_oc_sc_figure_n = ft_vec_dot(sc->oc, sc->figure[sc->m].n);

	sc->figure[sc->m].k = (float)tan(sc->figure[sc->m].angl);
	sc->k1 = dot_dd_dd - (1 + sc->figure[sc->m].k * sc->figure[sc->m].k) *
	dot_dd_sc_figure_n * dot_dd_sc_figure_n ;
	sc->k2 = 2 * (dot_dd_oc - (1 + sc->figure[sc->m].k * sc->figure[sc->m].k) *
	(dot_dd_sc_figure_n * dot_oc_sc_figure_n));
	sc->k3 = dot_oc_oc - (1 + sc->figure[sc->m].k * sc->figure[sc->m].k) *
	(dot_oc_sc_figure_n * dot_oc_sc_figure_n);
	sc->discr = sc->k2 * sc->k2 - 4 * sc->k1 * sc->k3;
	if (sc->discr < 0)
	{
		sc->t1 = 0;
		sc->t2 = 0;
		return ;
	}
	sc->t1 = (-sc->k2 + sqrtf(sc->discr)) / (2 * sc->k1);
	sc->t2 = (-sc->k2 - sqrtf(sc->discr)) / (2 * sc->k1);
	sc->figure[sc->m].p1.x = sc->cam.o.x + sc->t1 * sc->dd.x;
	sc->figure[sc->m].p1.y = sc->cam.o.y + sc->t1 * sc->dd.y;
	sc->figure[sc->m].p1.z = sc->cam.o.z + sc->t1 * sc->dd.z;

	ft_vec_sub(sc->figure[sc->m].p1, sc->figure[sc->m].o, &sc->figure[sc->m].pc);
	sc->figure[sc->m].m_figure_length = ft_vec_dot(sc->figure[sc->m].pc,
	sc->figure[sc->m].n);

	if (sc->figure[sc->m].m_figure_length <= 0 || sc->figure[sc->m].m_figure_length >= (float)sc->figure[sc->m].length)
	{
		sc->t1 = -1;
	}
	sc->figure[sc->m].p2.x = sc->cam.o.x + sc->t2 * sc->dd.x;
	sc->figure[sc->m].p2.y = sc->cam.o.y + sc->t2 * sc->dd.y;
	sc->figure[sc->m].p2.z = sc->cam.o.z + sc->t2 * sc->dd.z;

	ft_vec_sub(sc->figure[sc->m].p2, sc->figure[sc->m].o, &sc->figure[sc->m].pc);
	sc->figure[sc->m].m_figure_length = ft_vec_dot(sc->figure[sc->m].pc,
	sc->figure[sc->m].n);

	if (sc->figure[sc->m].m_figure_length <= 0 || sc->figure[sc->m].m_figure_length >= (float)sc->figure[sc->m].length)
	{
		sc->t2 = -1;
	}
}

void	traceray(t_scene *sc)
{
	// if (sc->i == 0 && sc->j == 0)
	// {
	// 	printf("sc->n.length = %f\n", sc->n.length);
	// }
	sc->m = 0;
	sc->closfig = -1;
	sc->clost = sc->eov;
	while (sc->m < sc->pa.nof)
	{
		ft_vec_sub(sc->cam.o, sc->figure[sc->m].o, &sc->oc);
		intersection(sc);
	}
	ft_vec_sub(sc->cam.o, sc->figure[sc->closfig].o, &sc->oc);
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
	if (sc->n.length == 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
	if (sc->figure[sc->closfig].o.y > sc->cam.o.y && sc->n.y == 1)
		sc->n.y *= -1;
	if (sc->figure[sc->closfig].o.y < sc->cam.o.y && sc->n.y == -1)
		sc->n.y *= -1;
	if (sc->figure[sc->closfig].o.x > sc->cam.o.x && sc->n.x == 1)
		sc->n.x *= -1;
	if (sc->figure[sc->closfig].o.x < sc->cam.o.x && sc->n.x == -1)
		sc->n.x *= -1;
	if (sc->figure[sc->closfig].o.z > sc->cam.o.z && sc->n.z == 1)
		sc->n.z *= -1;
	if (sc->figure[sc->closfig].o.z < sc->cam.o.z && sc->n.z == -1)
		sc->n.z *= -1;
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
	if (sc->n.length == 0)
		sc->n.length = 1;
	sc->n.x = sc->n.x / sc->n.length;
	sc->n.y = sc->n.y / sc->n.length;
	sc->n.z = sc->n.z / sc->n.length;
}
