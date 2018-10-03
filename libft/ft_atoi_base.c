/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:38:38 by vordynsk          #+#    #+#             */
/*   Updated: 2018/10/03 21:38:39 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		base(char c, int base)
{
	char		buff[17];
	int			i;

	ft_strcpy(buff, "0123456789ABCDEF");
	i = 0;
	while (i < base)
	{
		if (buff[i] == c)
			return (1);
	}
	return (-1);
}

int				ft_atoi_base(char const *str, int base)
{
	int		i;
	size_t	num;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	num = 0;
	while (base(str[i], base) > 0)
	{
		num = (num * base) + (str[i++] - 48);
	}
}
