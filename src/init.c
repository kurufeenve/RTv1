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
	sc->eov = 1000.0;
	sc->clost = sc->eov;
}

void	default_sc(t_scene *sc)
{
	sc->nof = 5;
	sc->figure = (t_figure *)malloc(sizeof(t_figure) * 5);
	sc->figure[0].type = 0;
	sc->figure[0].radius = 50;
	sc->figure[0].o.x = -40;
	sc->figure[0].o.y = 0;
	sc->figure[0].o.z = 250;
	sc->figure[0].color.color = 0xffffff;
	sc->figure[1].type = 0;
	sc->figure[1].radius = 50;
	sc->figure[1].o.x = 40;
	sc->figure[1].o.y = 0;
	sc->figure[1].o.z = 250;
	sc->figure[1].color.color = 0xffffff;
	sc->figure[2].type = 3;
	sc->figure[2].o.x = 0;
	sc->figure[2].o.y = 50;
	sc->figure[2].o.z = 0;
	sc->figure[2].n.x = 0;
	sc->figure[2].n.y = -1;
	sc->figure[2].n.z = 0;
	sc->figure[2].color.color = 0xffffff;
	default_sc2(sc);
}

void	default_sc2(t_scene *sc)
{
	sc->figure[3].type = 1;
	sc->figure[3].radius = 20;
	sc->figure[3].o.x = 40;
	sc->figure[3].o.y = 0;
	sc->figure[3].o.z = 250;
	sc->figure[3].n.x = 0;
	sc->figure[3].n.y = -1;
	sc->figure[3].n.z = 0;
	sc->figure[3].color.color = 0xffffff;
	sc->figure[4].type = 2;
	sc->figure[4].angl = 0.5235987756;
	sc->figure[4].o.x = -40;
	sc->figure[4].o.y = -50;
	sc->figure[4].o.z = 250;
	sc->figure[4].n.x = 0;
	sc->figure[4].n.y = -1;
	sc->figure[4].n.z = 0;
	sc->figure[4].color.color = 0xffffff;
	sc->p_l.o.x = 0;
	sc->p_l.o.y = 0;
	sc->p_l.o.z = 0;
	sc->p_l.intensity = 0.95;
}
