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

// void	render(t_scene *sc, t_sdl *s)
// {
// 	sc->i = -sc->cw/2;
// 	while (sc->i < sc->cw/2)
// 	{
// 		sc->j = -sc->ch/2;
// 		while (sc->j < sc->ch/2)
// 		{
// 			canvtoview(sc);
// 			// if (sc->i == 0 && sc->j == 0)
// 			// 	printf("sc->dd.x = %f, sc->dd.y = %f, sc->dd.z = %f\n", sc->dd.x, sc->dd.y, sc->dd.z);
// 			//intersect_sph(sc);
// 			traceray(sc);
// 			sc->i += sc->cw/2;
// 			sc->j += sc->ch/2;
// 			//printf("sc->i = %d, sc->j = %d\n", sc->i, sc->j);
// 			putpixel(s, sc->i, sc->j, sc->color.color);
// 			sc->i -= sc->cw/2;
// 			sc->j -= sc->ch/2;
// 			sc->j++;
// 		}
// 		sc->i++;
// 	}
// 	printf("sc->cam.o.x = %f, sc->cam.o.y = %f, sc->cam.o.z = %f, sc->cam.ro.x = %f, sc->cam.ro.y = %f, sc->cam.ro.z = %f\n", sc->cam.o.x, sc->cam.o.y, sc->cam.o.z, sc->cam.ro.x, sc->cam.ro.y, sc->cam.ro.z);
// }

// void	canvtoview(t_scene *sc)
// {
// 	sc->dd.x = (float)sc->i * (float)sc->vw / (float)sc->cw;
// 	sc->dd.y = (float)sc->j * (float)sc->vh / (float)sc->ch;
// 	sc->dd.z = (float)sc->d;
// 	camera_rotation(&sc->dd, sc->cam.ro);
// }

// void	camera_rotation(t_vector *n, t_vector ro)
// {
// 	float	tmpx;
// 	float	tmpy;
// 	float	tmpz;

// 	tmpx = n->x;
// 	tmpy = n->y;
// 	tmpz = n->z;
// 	n->x = tmpx * cos(ro.y) * cos(ro.z) + tmpz * sin(ro.y) -
// 	tmpy * cos(ro.y) * sin(ro.z);
// 	n->y = -tmpz * cos(ro.y) * sin(ro.x) + tmpx * (cos(ro.z) *
// 	sin(ro.x) * sin(ro.y) + cos(ro.x) * sin(ro.z)) + tmpy * (cos(ro.x) * cos(ro.z) -
// 	sin(ro.x) * sin(ro.y) * sin(ro.z));
// 	n->z = tmpz * cos(ro.x) * cos(ro.y) + tmpx * (sin(ro.x) *
// 	sin(ro.z) - cos(ro.x) * cos(ro.z) * sin(ro.y)) + tmpy * (cos(ro.z) * sin(ro.x) +
// 	cos(ro.x) * sin(ro.y) * sin(ro.z));
// }

// void	intersect_sph(t_scene *sc)
// {
// 	ft_vec_sub(sc->cam.o, sc->figure[0].o, &sc->oc);
// 	sc->k1 = sc->dd.x * sc->dd.x + sc->dd.y * sc->dd.y + sc->dd.z * sc->dd.z;
// 	sc->k2 = 2 * (sc->oc.x * sc->dd.x + sc->oc.y * sc->dd.y +
// 	sc->oc.z * sc->dd.z);
// 	sc->k3 = sc->oc.x * sc->oc.x + sc->oc.y * sc->oc.y + sc->oc.z * sc->oc.z -
// 	sc->figure[0].radius * sc->figure[0].radius;
// 	sc->discr = sc->k2 * sc->k2 - 4 * sc->k1 * sc->k3;
// 	if (sc->discr < 0)
// 	{
// 		sc->t1 = 0;
// 		sc->t2 = 0;
// 		return ;
// 	}
// 	sc->t1 = (-sc->k2 + sqrtf(sc->discr)) / (2 * sc->k1);
// 	sc->t2 = (-sc->k2 - sqrtf(sc->discr)) / (2 * sc->k1);
// 	// if (sc->i == -50 && sc->j == 0)
// 	// 	printf("sc->k1 = %f, sc->k2 = %f, sc->k3 = %f, sc->discr = %f, sc->t1 = %f, sc->t2 = %f\n", sc->k1, sc->k2, sc->k3, sc->discr, sc->t1, sc->t2);
// }

// void	traceray(t_scene *sc)
// {
// 	intersect_sph(sc);
// 	sc->clost = 1;
// 	// if (sc->t1 > 1 && sc->t1 < sc->clost)
// 	// 	sc->clost = sc->t1;
// 	// if (sc->t2 > 1 && sc->t2 < sc->clost)
// 	// 	sc->clost = sc->t2;
// 	//printf("sc->t1 = %f, sc->t2 = %f\n", sc->t1, sc->t2);
// 	if (sc->t1 > 1 || sc->t2 > 1)
// 	{
// 		if (sc->t1 > sc->t2)
// 			sc->clost = sc->t2;
// 		else
// 			sc->clost = sc->t1;
// 		sc->color.color = sc->figure[0].color.color;
// 	}
// 	else
// 	{
// 		sc->color.color = 0x000000;
// 		sc->clost = 0;
// 	}
// 	// if (sc->i == -50 && sc->j == 0)
// 	// 	printf("sc->p.x = %f, sc->p.y = %f, sc->p.z = %f, sc->clost = %f, sc->dd.x = %f\n", sc->p.x, sc->p.y, sc->p.z, sc->clost, sc->dd.x);
// 	sc->p.x = sc->cam.o.x + sc->clost * sc->dd.x;
// 	sc->p.y = sc->cam.o.y + sc->clost * sc->dd.y;
// 	sc->p.z = sc->cam.o.z + sc->clost * sc->dd.z;
// 	// if (sc->i == -50 && sc->j == 0)
// 	// 	printf("sc->p.x = %f, sc->p.y = %f, sc->p.z = %f, sc->clost = %f, sc->dd.x = %f\n", sc->p.x, sc->p.y, sc->p.z, sc->clost, sc->dd.x);
// 	sc->n.x = sc->p.x - sc->figure[0].o.x;
// 	sc->n.y = sc->p.y - sc->figure[0].o.y;
// 	sc->n.z = sc->p.z - sc->figure[0].o.z;
// 	sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y +
// 	sc->n.z * sc->n.z);
// 	sc->n.x = sc->n.x / sc->n.length;
// 	sc->n.y = sc->n.y / sc->n.length;
// 	sc->n.z = sc->n.z / sc->n.length;
// 	// if (sc->i == -50 && sc->j == 0)
// 	// 	printf("sc->n.x = %f, sc->n.y = %f, sc->n.z = %f\n", sc->n.x, sc->n.y, sc->n.z);
// 	if (sc->clost > 1)
// 		lighting(sc);
// 	sc->color.channel[0] *= sc->intensity;
// 	sc->color.channel[1] *= sc->intensity;
// 	sc->color.channel[2] *= sc->intensity;
// 	// if (sc->i == 0 && sc->j == -250)
// 	// 	printf("sc->intensity = %f, sc->color.color = %x\n", sc->intensity, sc->color.color);
// }

// void	lighting(t_scene *sc)
// {
// 	sc->intensity = 0.05;
// 	sc->l.x = sc->p_l.o.x - sc->p.x;
// 	sc->l.y = sc->p_l.o.y - sc->p.y;
// 	sc->l.z = sc->p_l.o.z - sc->p.z;
// 	sc->n_dot_l = sc->n.x * sc->l.x + sc->n.y * sc->l.y + sc->n.z * sc->l.z;
// 	if (sc->n_dot_l > 0)
// 		sc->intensity += sc->p_l.intensity * sc->n_dot_l / (sqrt(sc->n.x * sc->n.x
// 		+ sc->n.y * sc->n.y + sc->n.z * sc->n.z) * sqrt(sc->l.x * sc->l.x + sc->l.y
// 		* sc->l.y + sc->l.z * sc->l.z));
// 	//printf("sc->intensity = %f\n", sc->intensity);
// }
