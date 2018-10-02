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
	sc->pa.index = 0;
	sc->pa.prev_type = 0;
	sc->pa.index2 = 0;
	sc->pa.nof = 0;
	sc->pa.boo = 1;
}
