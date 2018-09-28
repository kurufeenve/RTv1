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
	//printf("sc->p_l.intensity = %f\n", sc->p_l.intensity);
	sc->i = -sc->cw/2;
	while (sc->i < sc->cw/2)
	{
		sc->j = -sc->ch/2;
		while (sc->j < sc->ch/2)
		{
			canvtoview(sc);
			// if (sc->i == 0 && sc->j == 0)
			// 	printf("sc->dd.x = %f, sc->dd.y = %f, sc->dd.z = %f\n", sc->dd.x, sc->dd.y, sc->dd.z);
			//intersect_sph(sc);
			traceray(sc);
			sc->i += sc->cw/2;
			sc->j += sc->ch/2;
			//printf("sc->i = %d, sc->j = %d\n", sc->i, sc->j);
			putpixel(s, sc->i, sc->j, sc->color.color);
			sc->i -= sc->cw/2;
			sc->j -= sc->ch/2;
			sc->j++;
		}
		sc->i++;
	}
	//printf("sc->cam.o.x = %f, sc->cam.o.y = %f, sc->cam.o.z = %f, sc->cam.ro.x = %f, sc->cam.ro.y = %f, sc->cam.ro.z = %f\n", sc->cam.o.x, sc->cam.o.y, sc->cam.o.z, sc->cam.ro.x, sc->cam.ro.y, sc->cam.ro.z);
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
	sin(ro.x) * sin(ro.y) + cos(ro.x) * sin(ro.z)) + tmpy * (cos(ro.x) * cos(ro.z) -
	sin(ro.x) * sin(ro.y) * sin(ro.z));
	n->z = tmpz * cos(ro.x) * cos(ro.y) + tmpx * (sin(ro.x) *
	sin(ro.z) - cos(ro.x) * cos(ro.z) * sin(ro.y)) + tmpy * (cos(ro.z) * sin(ro.x) +
	cos(ro.x) * sin(ro.y) * sin(ro.z));
}

void	intersect_sph(t_scene *sc)
{
	// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
	// 	printf("sc->m = %d\n", sc->m);
	ft_vec_sub(sc->cam.o, sc->figure[sc->m].o, &sc->oc);
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
// 	if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
// 		printf("sc->oc.x = %f, sc->oc.y = %f, sc->oc.z = %f\nsc->k1 = %f, sc->k2 = %f, sc->k3 = %f, \
// sc->discr = %f, sc->t1 = %f, sc->t2 = %f\n\n", sc->oc.x, sc->oc.y, sc->oc.z, \
//		sc->k1, sc->k2, sc->k3, sc->discr, sc->t1, sc->t2);
}

void	intersect_plane(t_scene *sc)
{
	float	buff;

	ft_vec_sub(sc->cam.o, sc->figure[sc->m].o, &sc->oc);
	buff = (sc->dd.x * sc->figure[sc->m].n.x + sc->dd.y * sc->figure[sc->m].n.y +
	sc->dd.z * sc->figure[sc->m].n.z);
	if (buff != 0)
		sc->t1 = -(sc->oc.x * sc->figure[sc->m].n.x + sc->oc.y *
		sc->figure[sc->m].n.y + sc->oc.z * sc->figure[sc->m].n.z) / buff;
		// if (sc->t1 < 0)
		// 	sc->t1 *= -1;
	else
		sc->t1 = 0;
	sc->t2 = sc->t1;
}

void	traceray(t_scene *sc)
{
	sc->m = 0;
	sc->closfig = -1;
	sc->clost = sc->eov;
	while (sc->m < sc->nof)
	{
		if (sc->figure[sc->m].type == 0)
			intersect_sph(sc);
		if (sc->figure[sc->m].type == 3)
			intersect_plane(sc);
		if (sc->t1 > 1 && sc->t1 < sc->clost)
		{
			sc->clost = sc->t1;
			sc->closfig = sc->m;
			// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
			// 	printf("sc->m = %d, sc->closfig = %d, sc->clost = %f, sc->t1 = %f\n", sc->m, \
			// sc->closfig, sc->clost, sc->t1);
		}
		if (sc->t2 > 1 && sc->t2 < sc->clost)
		{
			sc->clost = sc->t2;
			sc->closfig = sc->m;
			// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
			// 	printf("sc->m = %d, sc->closfig = %d, sc->clost = %f, sc->t2 = %f\n", sc->m, \
			// sc->closfig, sc->clost, sc->t2);
		}
		if (sc->closfig > -1 || sc->clost != sc->eov)
			sc->color.color = sc->figure[sc->closfig].color.color;
		// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
		// 	printf("sc->m = %d, sc->closfig = %d, sc->clost = %f, sc->t1 = %f, sc->t2 = %f\n", sc->m, \
		// 	sc->closfig, sc->clost, sc->t1, sc->t2);

		if (sc->closfig == -1)
			sc->color.color = 0x000000;
		sc->m++;
	}
		// if (sc->i == -50 && sc->j == 0)
		// 	printf("sc->p.x = %f, sc->p.y = %f, sc->p.z = %f, sc->clost = %f, sc->dd.x = %f\n", sc->p.x, sc->p.y, sc->p.z, sc->clost, sc->dd.x);
		sc->p.x = sc->cam.o.x + sc->clost * sc->dd.x;
		sc->p.y = sc->cam.o.y + sc->clost * sc->dd.y;
		sc->p.z = sc->cam.o.z + sc->clost * sc->dd.z;
		// if (sc->i == 0 && sc->j == 0)
		// 	printf("sc->p.x = %f, sc->p.y = %f, sc->p.z = %f, sc->clost = %f, sc->dd.x = %f\n\n", sc->p.x, sc->p.y, sc->p.z, sc->clost, sc->dd.x);
		// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
		// 	printf("sc->p.x = %f, sc->p.y = %f, sc->p.z = %f, sc->clost = %f, sc->dd.x = %f\n\n", sc->p.x, sc->p.y, sc->p.z, sc->clost, sc->dd.x);
		sc->n.x = sc->p.x - sc->figure[sc->closfig].o.x;
		sc->n.y = sc->p.y - sc->figure[sc->closfig].o.y;
		sc->n.z = sc->p.z - sc->figure[sc->closfig].o.z;
		// if ((sc->i == -60 && sc->j == 0) || (sc->i == 60 && sc->j == 0))
		// {
		// 	printf("sc->m = %d, sc->figure[sc->m].o.x = %f, sc->figure[sc->m].o.y = %f, sc->figure[sc->m].o.z = %f\n", sc->m, sc->figure[sc->m].o.x, sc->figure[sc->m].o.y, sc->figure[sc->m].o.z);
		// 	printf("sc->n.x = %f, sc->n.y = %f, sc->n.z = %f\n\n", sc->n.x, sc->n.y, sc->n.z);
		// }
		sc->n.length = sqrt(sc->n.x * sc->n.x + sc->n.y * sc->n.y +
		sc->n.z * sc->n.z);
		sc->n.x = sc->n.x / sc->n.length;
		sc->n.y = sc->n.y / sc->n.length;
		sc->n.z = sc->n.z / sc->n.length;
		// if (sc->i == 0 && sc->j == 0)
		// 	printf("sc->n.x = %f, sc->n.y = %f, sc->n.z = %f\n", sc->n.x, sc->n.y, sc->n.z);
		if (sc->clost > 1)
			lighting(sc);
		sc->color.channel[0] *= sc->intensity;
		sc->color.channel[1] *= sc->intensity;
		sc->color.channel[2] *= sc->intensity;
		// if (sc->i == 60 && sc->j == 0)
		// 	printf("sc->intensity = %f, sc->color.color = %x\n", sc->intensity, sc->color.color);
}

void	lighting(t_scene *sc)
{
	sc->intensity = 0.05;
	sc->l.x = sc->p_l.o.x - sc->p.x;
	sc->l.y = sc->p_l.o.y - sc->p.y;
	sc->l.z = sc->p_l.o.z - sc->p.z;
	// sc->l.length = sqrt(sc->l.x * sc->l.x + sc->l.y * sc->l.y +
	// sc->l.z * sc->l.z);
	// sc->l.x = sc->l.x / sc->l.length;
	// sc->l.y = sc->l.y / sc->l.length;
	// sc->l.z = sc->l.z / sc->l.length;
	// if (sc->i == 0 && sc->j == 0)
	// if (sc->i == -60 && sc->j == 0)
		// printf("sc->l.x = %f, sc->l.y = %f, sc->l.z = %f\n", sc->l.x, sc->l.y, sc->l.z);
	// if (sc->i == 60 && sc->j == 0)
	// 	printf("");
	sc->n_dot_l = sc->n.x * sc->l.x + sc->n.y * sc->l.y + sc->n.z * sc->l.z;
	// if (sc->i == 0 && sc->j == 0)
	// 	printf("sc->n_dot_l = %f\n", sc->n_dot_l);
	if (sc->n_dot_l > 0)
		sc->intensity += sc->p_l.intensity * sc->n_dot_l / (sqrt(sc->n.x * sc->n.x
		+ sc->n.y * sc->n.y + sc->n.z * sc->n.z) * sqrt(sc->l.x * sc->l.x + sc->l.y
		* sc->l.y + sc->l.z * sc->l.z));
	// if (sc->i == 0 && sc->j == 0)
	// 	printf("sc->intensity = %f, sc->n_dot_l = %f, |n|*|l| = %f\n", sc->intensity, sc->n_dot_l, (sqrt(sc->n.x * sc->n.x
		// + sc->n.y * sc->n.y + sc->n.z * sc->n.z) * sqrt(sc->l.x * sc->l.x + sc->l.y
		// * sc->l.y + sc->l.z * sc->l.z)));
}
