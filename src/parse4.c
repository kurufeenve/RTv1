/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:18:51 by vordynsk          #+#    #+#             */
/*   Updated: 2018/10/06 17:18:52 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	read_light(t_scene *sc)
{
	read_o_light(sc);
	read_intensity(sc);
}

void	read_camera(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", 0, 0)) == -1)
		errors(11);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(11);
	sc->cam.o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", 0, 0)) == -1)
		errors(11);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(11);
	sc->cam.o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", 0, 0)) == -1)
		errors(11);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(11);
	sc->cam.o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	placement_check(sc->cam.o);
}

void	read_intensity(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "intensity=", 0, 0)) == -1)
		errors(10);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 10, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(10);
	sc->p_l.intensity = (float)ft_atoi(sc->pa.f_buff);
	if (sc->p_l.intensity < 0)
		sc->p_l.intensity *= -1;
	sc->p_l.intensity /= 100.;
	if (sc->p_l.intensity > 0.95f)
		sc->p_l.intensity = 0.95f;
	ft_strdel(&sc->pa.f_buff);
}

void	read_o_light(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", 0, 0)) == -1)
		errors(10);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(10);
	sc->p_l.o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", 0, 0)) == -1)
		errors(10);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(10);
	sc->p_l.o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", 0, 0)) == -1)
		errors(10);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(10);
	sc->p_l.o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	placement_check(sc->p_l.o);
}

void	read_a_figure(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ax=", 0, 0)) == -1)
		errors(6);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(6);
	sc->figure[sc->i].a.x = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ay=", 0, 0)) == -1)
		errors(6);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(6);
	sc->figure[sc->i].a.y = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "az=", 0, 0)) == -1)
		errors(6);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(6);
	sc->figure[sc->i].a.z = (float)ft_atoi(sc->pa.f_buff) * (float)0.0174532925;
	ft_strdel(&sc->pa.f_buff);
}
