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
	sc->figure[sc->i].type = sc->pa.type;
	read_o_light(sc);
	read_intensity(sc);
}

void	read_camera(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->cam.o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->cam.o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->cam.o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}

void	read_intensity(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "intensity=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 10, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->p_l.intensity = (float)ft_atoi(sc->pa.f_buff) / 100.;
	ft_strdel(&sc->pa.f_buff);
}

void	read_o_light(t_scene *sc) // temporary before I imlement multy_point light
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->p_l.o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->p_l.o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", 0, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->p_l.o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}
