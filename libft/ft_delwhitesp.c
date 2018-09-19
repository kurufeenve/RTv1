/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delwhitesp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:49:03 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/17 18:49:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	count(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		{
			i++;
			continue ;
		}
		j++;
		i++;
	}
	return (j);
}

void		ft_delwhitesp(char **str)
{
	char	*buff;
	char	*res;
	int		i;

	res = ft_strnew(count(*str));
	buff = res;
	i = 0;
	while ((*str)[i] != '\0')
	{
		if (((*str)[i] >= 9 && (*str)[i] <= 13) || (*str)[i] == 32)
		{
			i++;
			continue ;
		}
		*buff = (*str)[i];
		buff++;
		i++;
	}
	ft_strdel(str);
	*str = res;
}
