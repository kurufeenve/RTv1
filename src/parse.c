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

}

void	read_scene(t_scene *sc)
{
	int		t;
	char	*buff;

	buff = ft_strchr(sc.filename, 46);
	if (ft_strcmp(buff, ".sc") != 0)
	{
		printf("wrong file extension\n");
		exit(0);
	}
	sc->fd = open(sc->filename, O_RDONLY);
	t = 1;
	while (t > 0)
	{
		t = get_next_line(sc->fd, &sc->line);
		if (t < 0)
		{
			printf("\n===	!!! NOT A FILE !!!	===\n\n");
			exit(0);
		}
		sc->str = ft_strjoin2(sc->str, sc->line);
	}
}

void	fig_count(t_scene *sc)
{
	int		i;

	i = 0;
	ob = 0;
	cb = 0;
	while (sc->str[i] != '\0')
	{
		if (sc->str[i] == '{')
			ob++;
		if (sc->str[i] == '}')
			cb++;
		i++;
	}
	printf("ob = %d, cb = %d\n", ob, cb);
	if (ob != cb)
	{
		printf("syntax error\n");
		exit (0);
	}
}
