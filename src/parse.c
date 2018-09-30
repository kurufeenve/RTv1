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

	buff = ft_strchr(sc->filename, 46);
	if (ft_strcmp(buff, ".sc") != 0)
	{
		ft_putstr("wrong file extension\n");
		system("leaks RTv1");
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
			system("leaks RTv1");
			exit(0);
		}
		sc->str = ft_strjoin2(sc->str, sc->line);
	}
	ft_delwhitesp(&sc->str);
	printf("sc->str = %s\n", sc->str);
}

void	validation(t_scene *sc)
{
	sc->i = 0;
	while (sc->str[sc->i] != '\0')
	{
		if (ft_isalnum(sc->str[sc->i]) != 1 && sc->str[sc->i] != ';' &&
		sc->str[sc->i] != '=' && sc->str[sc->i] != '-')
		{
			ft_putstr("syntax error\n");
			system("leaks RTv1");
			exit(0);
		}
		sc->i++;
	}
	sc->i = 0;
}

void	count_figures(t_scene *sc)
{
	while (1)
	{
		if ((sc->index = ft_indexof(sc->str, "type=", sc->index, 0)) == -1)
			break ;
		sc->index2 = ft_strnfind(sc->str, ';', sc->index);
		sc->buff = ft_strnsub(sc->str, sc->index + 5, sc->index2);
		sc->type = ft_atoi(sc->buff);
		if (sc->type >= 0 && sc->type <=3)
			sc->nof++;
		ft_strdel(&sc->buff);
		sc->index++;
	}
}

void	parse_fig(t_scene *sc)
{
	count_figures(sc);
	printf("sc->nof = %d\n", sc->nof);
	while (1)
	{
		if ((sc->index = ft_indexof(sc->str, "type=", sc->index, 0)) == -1)
			break ;
		sc->index2 = ft_strnfind(sc->str, ';', sc->index);
		sc->buff = ft_strnsub(sc->str, sc->index + 5, sc->index2);
		sc->type = ft_atoi(sc->buff);
		ft_strdel(&sc->buff);
		//read_figures(sc);
		sc->index++; // might not need it in future
	}
}
