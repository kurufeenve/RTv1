/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:36:45 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/16 16:36:47 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_parse(t_scene *sc)
{
	read_scene(sc);
	validation(sc);
	parse_fig(sc);
}

void	read_scene(t_scene *sc)
{
	int		t;
	char	*buff;

	buff = ft_strchr(sc->pa.filename, 46);
	if (ft_strcmp(buff, ".sc") != 0)
		errors(1);
	sc->pa.fd = open(sc->pa.filename, O_RDONLY);
	t = 1;
	while (t > 0)
	{
		t = get_next_line(sc->pa.fd, &sc->pa.line);
		if (t < 0)
			errors(2);
		sc->pa.str = ft_strjoin2(sc->pa.str, sc->pa.line);
	}
	ft_delwhitesp(&sc->pa.str);
}

void	validation(t_scene *sc)
{
	sc->i = 0;
	while (sc->pa.str[sc->i] != '\0')
	{
		if (ft_isalnum(sc->pa.str[sc->i]) != 1 && sc->pa.str[sc->i] != ';' &&
		sc->pa.str[sc->i] != '=' && sc->pa.str[sc->i] != '-')
			errors(3);
		sc->i++;
	}
	sc->i = 0;
}

void	count_figures(t_scene *sc)
{
	while (1)
	{
		if ((sc->pa.index = ft_indexof(sc->pa.str, "type=",
		sc->pa.index, 0)) == -1)
			break ;
		sc->pa.index2 = ft_strnfind(sc->pa.str, ';', sc->pa.index);
		sc->pa.buff = ft_strnsub(sc->pa.str, sc->pa.index + 5, sc->pa.index2);
		if (ft_isnumber(sc->pa.buff) == 0)
			errors(3);
		sc->pa.type = ft_atoi(sc->pa.buff);
		if (sc->pa.type >= 0 && sc->pa.type <= 3)
			sc->pa.nof++;
		ft_strdel(&sc->pa.buff);
		sc->pa.index++;
	}
	sc->figure = (t_figure *)malloc(sizeof(t_figure) * sc->pa.nof);
	sc->pa.index = 0;
	sc->pa.index2 = 0;
}

void	parse_fig(t_scene *sc)
{
	sc->i = 0;
	count_figures(sc);
	while (sc->pa.boo > 0)
	{
		if ((sc->pa.index = ft_indexof(sc->pa.str, "type=", sc->pa.prev_type,
		0)) == -1)
			break ;
		sc->pa.index2 = ft_strnfind(sc->pa.str, ';', sc->pa.index);
		sc->pa.buff = ft_strnsub(sc->pa.str, sc->pa.index + 5, sc->pa.index2);
		sc->pa.type = ft_atoi(sc->pa.buff);
		ft_strdel(&sc->pa.buff);
		sc->pa.prev_type = sc->pa.index;
		sc->pa.index = ft_indexof(sc->pa.str, "type=", sc->pa.prev_type + 1, 0);
		if (sc->pa.index == -1 && (sc->pa.boo = -1))
			sc->pa.index = ft_strlen(sc->pa.str);
		sc->pa.buff = ft_strnsub(sc->pa.str, sc->pa.prev_type, sc->pa.index);
		read_figures(sc);
		ft_strdel(&sc->pa.buff);
		sc->i++;
		sc->pa.prev_type++;
	}
}
