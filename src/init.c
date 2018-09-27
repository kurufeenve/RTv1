/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:41:06 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/17 16:41:08 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	struct_init(t_scene *sc)
{
	// sc->figure = (t_figure *)malloc(sizeof(t_figure) * 1);
	// sphere(&sc->figure[0]);
	sc->cam.o.x = 0;
	sc->cam.o.y = 0;
	sc->cam.o.z = 0;
	sc->cam.ro.x = 0;
	sc->cam.ro.y = 0;
	sc->cam.ro.z = 0;
	sc->cw = 1000;
	sc->ch = 1000;
	sc->vw = 1;
	sc->vh = 1;
	sc->d = 1;
	sc->t1 = 0;
	sc->t2 = 0;
	sc->p_l.o.x = 100;
	sc->p_l.o.y = 0;
	sc->p_l.o.z = 150;
	sc->p_l.intensity = 0.95;
}

void	sphere(t_figure *f)
{
	f->type = 0;
	f->radius = 100;
	f->o.x = 0;
	f->o.y = 0;
	f->o.z = 250;
	f->color.color = 0xffffff;
}
