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
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ox=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].o.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oy=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].o.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "oz=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].o.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}

void	read_n_vector(t_scene *sc)
{
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "nx=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].n.x = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "ny=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].n.y = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "nz=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 3, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].n.z = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
}
