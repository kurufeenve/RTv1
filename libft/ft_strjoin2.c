/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:17:55 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/17 17:17:58 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin2(char *s1, char *s2)
{
	char	*buff1;
	char	*buff2;
	char	*res;

	if (s2 == NULL)
	{
		buff1 = ft_strdup(s1);
		ft_strdel(&s1);
		return (buff1);
	}
	else if (s1 == NULL)
	{
		buff2 = ft_strdup(s2);
		ft_strdel(&s2);
		return (buff2);
	}
	buff1 = s1;
	buff2 = s2;
	res = ft_strjoin(buff1, buff2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (res);
}
