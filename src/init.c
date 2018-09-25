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
	sc->figure = (t_figure *)malloc(sizeof(t_figure) * 4);
	sphere(&sc->figure[0]);
	cylinder(&sc->figure[1]);
	cone(&sc->figure[2]);
	plane(&sc->figure[3]);
	sc->cam.x = 0;
	sc->cam.y = 0;
	sc->cam.z = 0;
	sc->Cw = 1000;
	sc->Ch = 1000;
	sc->Vw = 1;
	sc->Vh = 1;
	sc->d = 1;
	sc->t1 = 0;
	sc->t2 = 0;
	sc->p_l.x = 100;
	sc->p_l.y = -400;
	sc->p_l.z = 200;
}

void	sphere(t_figure *f)
{
	f->name = ft_strnew(6);
	f->name = ft_strcpy(f->name, "sphere");
	f->radius = 100;
	f->o.x = 0;
	f->o.y = 0;
	f->o.z = 250;
	f->color.color = 0xffffff;
}

void	cylinder(t_figure *f)
{
	f->name = ft_strnew(8);
	f->name = ft_strcpy(f->name, "cylinder");
	f->radius = 50;
	f->height = 100;
	f->o.x = 250;
	f->o.y = 250;
	f->o.z = 250;
	f->ro_x = 0;
	f->ro_y = 90;
	f->ro_z = 90;
	f->color.color = 0xffffff;
}

void	cone(t_figure *f)
{
	f->name = ft_strnew(4);
	f->name = ft_strcpy(f->name, "cone");
	f->radius = 50;
	f->height = 80;
	f->o.x = 250;
	f->o.y = 250;
	f->o.z = 250;
	f->ro_x = 90;
	f->ro_y = 0;
	f->ro_z = 90;
	f->color.color = 0xffffff;
}

void	plane(t_figure *f)
{
	f->name = ft_strnew(5);
	f->name = ft_strcpy(f->name, "plane");
	f->length = 100;
	f->width = 100;
	f->o.x = 250;
	f->o.y = 250;
	f->o.z = 250;
	f->ro_x = 0;
	f->ro_y = 0;
	f->ro_z = 0;
	f->color.color = 0xffffff;
}
