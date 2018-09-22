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
	fig_count(sc);
	read_figures(sc);
}

void	read_scene(t_scene *sc)
{
	int		t;
	char	*buff;

	buff = ft_strchr(sc->filename, 46);
	if (ft_strcmp(buff, ".sc") != 0)
	{
		ft_putstr("wrong file extension\n");
		exit(0);
	}
	sc->fd = open(sc->filename, O_RDONLY);
	t = 1;
	while (t > 0)
	{
		t = get_next_line(sc->fd, &sc->line);
		if (t < 0)
		{
			ft_putstr("\n===	!!! NOT A FILE !!!	===\n\n");
			exit(0);
		}
		sc->str = ft_strjoin2(sc->str, sc->line);
	}
	ft_delwhitesp(&sc->str);
}

void	fig_count(t_scene *sc)
{
	sc->i = 0;
	sc->ob = 0;
	sc->cb = 0;
	while (sc->str[sc->i] != '\0')
	{
		if (sc->str[sc->i] == '{')
			sc->ob++;
		if (sc->str[sc->i] == '}')
			sc->cb++;
		if (sc->str[sc->i] != '[' && sc->str[sc->i] != ']' && sc->str[sc->i] !=
		'{' && sc->str[sc->i] != '}' && sc->str[sc->i] != ';' &&
		ft_isalnum(sc->str[sc->i]) != 1 && sc->str[sc->i] != ':')
		{
			ft_putstr("Unexpected symbol found\nEXIT\n");
			exit(0);
		}
		sc->i++;
	}
	if (sc->ob != sc->cb)
	{
		ft_putstr("syntax error\n");
		exit(0);
	}
	sc->figure = (t_figure *)malloc(sizeof(t_figure) * sc->ob);
}

void	read_figures(t_scene *sc)
{
	sc->i = 0;
	while (sc->str[i] '\0')
	{
		
	}
}
