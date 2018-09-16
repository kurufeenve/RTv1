/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:53:21 by vordynsk          #+#    #+#             */
/*   Updated: 2018/08/17 16:53:22 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	char	*buff;
	char	*res;
	int		len;

	len = ft_strlen(str);
	res = ft_strnew(len);
	buff = str;
	while (len > 0)
	{
		len--;
		res[len] = *buff;
		buff++;
	}
	ft_strcpy(str, res);
	ft_strdel(&res);
	return (str);
}
