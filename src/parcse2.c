/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcse2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 22:44:48 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/30 22:44:49 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	read_figures(t_scene *sc)
{
	if (sc->pa.type == 0)
		read_sphere(sc);
	else if (sc->pa.type == 1)
		read_cylinder(sc);
	else if (sc->pa.type == 2)
		read_cone(sc);
	else if (sc->pa.type == 3)
		read_plane(sc);
	else if (sc->pa.type == 4)
		read_light(sc);
	else if (sc->pa.type == 5)
		read_camera(sc);
	else if (sc->pa.type < 0 && sc->pa.type > 5)
		errors(4);
}

void	read_sphere(t_scene *sc)
{
	sc->figure[sc->i].type = sc->pa.type;
	read_radius(sc);
	read_o_vector(sc);
	read_color(sc);
}

void	read_plane(t_scene *sc)
{
	sc->figure[sc->i].type = sc->pa.type;
	read_o_vector(sc);
	read_n_vector(sc);
	read_color(sc);
}

void	read_cylinder(t_scene *sc)
{
	sc->figure[sc->i].type = sc->pa.type;
	read_radius(sc);
	read_o_vector(sc);
	read_n_vector(sc);
	read_color(sc);
}

void	read_cone(t_scene *sc)
{
	sc->figure[sc->i].type = sc->pa.type;
	read_angle(sc);
	read_o_vector(sc);
	read_n_vector(sc);
	read_color(sc);
}
