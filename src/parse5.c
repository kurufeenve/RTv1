/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:19:32 by vordynsk          #+#    #+#             */
/*   Updated: 2018/10/13 17:19:34 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	figure_rotation(t_vector *n, t_vector a)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;

	tmpx = n->x;
	tmpy = n->y;
	tmpz = n->z;
	n->x = tmpx * cos(a.y) * cos(a.z) + tmpz * sin(a.y) - tmpy * cos(a.y) *
	sin(a.z);
	n->y = -tmpz * cos(a.y) * sin(a.x) + tmpx * (cos(a.z) * sin(a.x) * sin(a.y)
	+ cos(a.x) * sin(a.z)) + tmpy * (cos(a.x) * cos(a.z) - sin(a.x) * sin(a.y)
	* sin(a.z));
	n->z = tmpz * cos(a.x) * cos(a.y) + tmpx * (sin(a.x) * sin(a.z) - cos(a.x) *
	cos(a.z) * sin(a.y)) + tmpy * (cos(a.z) * sin(a.x) + cos(a.x) * sin(a.y) *
	sin(a.z));
}

void	normalisation(t_vector *v)
{
	v->length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	if (v->length == 0)
		v->length = 1;
	v->x = v->x / v->length;
	v->y = v->y / v->length;
	v->z = v->z / v->length;
}

void	read_a_camera(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ax=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(3);
	sc->cam.ro.x = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ay=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(3);
	sc->cam.ro.y = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "az=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(3);
	sc->cam.ro.z = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
}
