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
	// else if (sc->pa.type == 1)
	// 	printf("sc->pa.type = %d, sc->pa.buff = %s\n", sc->pa.type, sc->pa.buff);
	// else if (sc->pa.type == 2)
	// 	printf("sc->pa.type = %d, sc->pa.buff = %s\n", sc->pa.type, sc->pa.buff);
	// else if (sc->pa.type == 3)
	// 	printf("sc->pa.type = %d, sc->pa.buff = %s\n", sc->pa.type, sc->pa.buff);
	// else if (sc->pa.type == 4)
	// 	printf("sc->pa.type = %d, sc->pa.buff = %s\n", sc->pa.type, sc->pa.buff);
	// else if (sc->pa.type == 5)
	// 	printf("sc->pa.type = %d, sc->pa.buff = %s\n", sc->pa.type, sc->pa.buff);
	else if (sc->pa.type < 0 && sc->pa.type > 5)
		errors(4);
}

void	read_sphere(t_scene *sc)
{
	sc->figure[sc->i].type = sc->pa.type;
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "radius=", sc->pa.prev_type, 0)) == -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 7, sc->pa.index2);
	if (ft_isnumber(sc->pa.f_buff) == 0)
			errors(3);
	sc->figure[sc->i].radius = ft_atoi(sc->pa.f_buff);
	ft_strdel(&sc->pa.f_buff);
	read_o_vector(sc);
}

void	read_color(t_scene *sc)
{
	int		i;

	i = 0;
	if ((sc->pa.index = ft_indexof(sc->pa.buff, "color=", sc->pa.prev_type, 0))
	== -1)
		errors(3);
	sc->pa.index2 = ft_strnfind(sc->pa.buff, ';', sc->pa.index);
	sc->pa.f_buff = ft_strnsub(sc->pa.buff, sc->pa.index + 6, sc->pa.index2);
	if (ft_strlen(sc->pa.f_buff) != 8)
		errors(3);
	while (i < 8)
	{
		if (ft_isdigit(sc->pa.f_buff[i]) == 0 && (sc->pa.f_buff[i] < 'a' ||
		sc->pa.f_buff[i] > 'f') && sc->pa.f_buff[i] != 'x')
			errors(3);
		i++;
	}
	sc->figure[sc->i].color.color = //ft_atoi(sc->pa.f_buff); ft_atoi_base!!!!!!!!!!!
	ft_strdel(&sc->pa.f_buff);
}


