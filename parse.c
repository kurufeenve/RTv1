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
	check_filename(*sc);
	sc->fd = open(sc->filename, O_RDONLY);
	printf("fd = %d\n", sc->fd);
}

void	check_filename(t_scene sc)
{
	char	*buff;

	buff = ft_strchr(sc.filename, 46);
	if (ft_strcmp(buff, ".sc") != 0)
	{
		printf("wrong file extension\n");
		exit(0);
	}
}
