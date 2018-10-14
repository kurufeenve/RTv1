/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:31:52 by vordynsk          #+#    #+#             */
/*   Updated: 2018/10/02 22:31:54 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	read_o_vector(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", 0, 0)) == -1)
		errors(7);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(7);
	sc->figure[sc->i].o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", 0, 0)) == -1)
		errors(7);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(7);
	sc->figure[sc->i].o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", 0, 0)) == -1)
		errors(7);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(7);
	sc->figure[sc->i].o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}

void	read_n_vector(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "nx=", 0, 0)) == -1)
		errors(8);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(8);
	sc->figure[sc->i].n.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ny=", 0, 0)) == -1)
		errors(8);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(8);
	sc->figure[sc->i].n.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "nz=", 0, 0)) == -1)
		errors(8);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(8);
	sc->figure[sc->i].n.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	normalisation(&sc->figure[sc->i].n);
}

void	read_color(t_scene *sc)
{
	int		i;

	i = 0;
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "color=0x", 0, 0))
	== -1)
		errors(9);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 8, sc->pa.index2);
	if (ft_strlen(sc->pa.f_buff) != 6)
		errors(3);
	while (i < 6)
	{
		if (ft_isdigit(sc->pa.f_buff[i]) == 0 && (sc->pa.f_buff[i] < 'a' ||
		sc->pa.f_buff[i] > 'f') && (sc->pa.f_buff[i] < 'A' ||
		sc->pa.f_buff[i] > 'F'))
			errors(9);
		i++;
	}
	sc->figure[sc->i].color.color = ft_atoi_base(sc->pa.f_buff, 16);
	ft_strdel(&sc->pa.f_buff);
}

void	read_radius(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "radius=", 0, 0)) == -1)
		errors(5);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 7, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(5);
	sc->figure[sc->i].radius = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}

void	read_angle(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "angle=", 0, 0)) == -1)
		errors(6);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 6, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
		errors(6);
	sc->figure[sc->i].angl = (float)ft_atoi(sc->pa.f_buff) * 0.0174532925;
	ft_strdel(&sc->pa.f_buff);
}
