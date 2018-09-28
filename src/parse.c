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

// void	ft_parse(t_scene *sc)
// {
// 	read_scene(sc);
// 	validation(sc);
// 	parse_fig(sc);
// }

// void	read_scene(t_scene *sc)
// {
// 	int		t;
// 	char	*buff;

// 	buff = ft_strchr(sc->filename, 46);
// 	if (ft_strcmp(buff, ".sc") != 0)
// 	{
// 		ft_putstr("wrong file extension\n");
// 		exit(0);
// 	}
// 	sc->fd = open(sc->filename, O_RDONLY);
// 	t = 1;
// 	while (t > 0)
// 	{
// 		t = get_next_line(sc->fd, &sc->line);
// 		if (t < 0)
// 		{
// 			ft_putstr("\n===	!!! NOT A FILE !!!	===\n\n");
// 			exit(0);
// 		}
// 		sc->str = ft_strjoin2(sc->str, sc->line);
// 	}
// 	ft_delwhitesp(&sc->str);
// 	printf("sc->str = %s\n", sc->str);
// }

// void	validation(t_scene *sc)
// {
// 	sc->i = 0;
// 	while (sc->str[sc->i] != '\0')
// 	{
// 		if (ft_isalnum(sc->str[sc->i]) != 1 && sc->str[sc->i] != ':' &&
// 		sc->str[sc->i] != ';' && sc->str[sc->i] != '.')
// 		{
// 			ft_putstr("syntax error\n");
// 			system("leaks RTv1");
// 			exit(0);
// 		}
// 		sc->i++;
// 	}
// 	sc->i = 0;
// }

// void	parse_fig(t_scene *sc)
// {
// 	sc->buf1 = 0;
// 	if ((sc->buf1 = ft_strnfind(sc->str, '.') != -1)
// 		while (sc->buf1 != -1)
// 		{
			
// 			sc->buff1 = ;
// 		}
// 	else
		
// }

void	param(t_scene *sc)
{
	sc->figure = (t_figure *)malloc(sizeof(t_figure) * sc->nof);
	sc->i = 0;
	while (sc->i < sc->nof)
	{
		//printf("sc->i = %d\n", sc->i);
		sc->j = 0;
		ft_putstr("0 - sphere\n1 - cylinder\n2 - cone\n3 - plane\nenter the \
		type of figure (you have 10 tries): ");
		while (sc->j < 10)
		{
			get_next_line(0, &sc->line);
			if (ft_strlen(sc->line) == 1 && sc->line[0] >= 48 && sc->line[0]
			<= 51)
			{
				sc->m = ft_atoi(sc->line);
				which_one(sc, sc->m);
				break ;
			}
			if (sc->line != NULL)
				ft_strdel(&sc->line);
			sc->j++;
			if (sc->j == 10)
				which_one(sc, 0);
		}
		sc->i++;
	}
}

void	which_one(t_scene *sc, int	n)
{
	sc->m = 0;
	ft_strdel(&sc->line);
	if (n == 0)
		sphere(sc);
	if (n == 1)
		cylinder(sc);
	if (n == 3)
		plane(sc);
}

void	sphere(t_scene *sc)
{
	sc->figure[sc->i].type = 0;
	ft_putstr("radius: ");
	sc->figure[sc->i].radius = read_data(sc);
	if (sc->figure[sc->i].radius < 0)
		sc->figure[sc->i].radius *= -1;
	ft_putstr("x: ");
	sc->figure[sc->i].o.x = read_data(sc);
	ft_putstr("y: ");
	sc->figure[sc->i].o.y = read_data(sc);
	ft_putstr("z: ");
	sc->figure[sc->i].o.z = read_data(sc);
	ft_putstr("color in dec: ");
	sc->figure[sc->i].color.color = read_data(sc);
	if (sc->figure[sc->i].color.color < 0)
		sc->figure[sc->i].color.color = 0xffffff;
}

void	plane(t_scene *sc)
{
	ft_putstr("x: ");
	sc->figure[sc->i].o.x = read_data(sc);
	ft_putstr("y: ");
	sc->figure[sc->i].o.y = read_data(sc);
	ft_putstr("z: ");
	sc->figure[sc->i].o.z = read_data(sc);
	ft_putstr("nx: ");
	sc->figure[sc->i].n.x = read_data(sc);
	ft_putstr("ny: ");
	sc->figure[sc->i].n.y = read_data(sc);
	ft_putstr("nz: ");
	sc->figure[sc->i].n.z = read_data(sc);
	ft_putstr("color in dec: ");
	sc->figure[sc->i].color.color = read_data(sc);
	if (sc->figure[sc->i].color.color < 0)
		sc->figure[sc->i].color.color = 0xffffff;
}

int		read_data(t_scene *sc)
{
	int		n;

	if (sc->line != NULL)
		ft_strdel(&sc->line);
	get_next_line(0, &sc->line);
	n = ft_atoi(sc->line);
	ft_strdel(&sc->line);
	return (n);
}

void	cylinder(t_scene *sc)
{
	sc->figure[sc->i].type = 1;
	ft_putstr("radius: ");
	sc->figure[sc->i].radius = read_data(sc);
	if (sc->figure[sc->i].radius < 0)
		sc->figure[sc->i].radius *= -1;
	ft_putstr("x: ");
	sc->figure[sc->i].o.x = read_data(sc);
	ft_putstr("y: ");
	sc->figure[sc->i].o.y = read_data(sc);
	ft_putstr("z: ");
	sc->figure[sc->i].o.z = read_data(sc);
	ft_putstr("nx: ");
	sc->figure[sc->i].n.x = read_data(sc);
	ft_putstr("ny: ");
	sc->figure[sc->i].n.y = read_data(sc);
	ft_putstr("nz: ");
	sc->figure[sc->i].n.z = read_data(sc);
	ft_putstr("color in dec: ");
	sc->figure[sc->i].color.color = read_data(sc);
	if (sc->figure[sc->i].color.color < 0)
		sc->figure[sc->i].color.color = 0xffffff;
}
