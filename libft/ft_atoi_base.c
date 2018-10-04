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
#include <stdio.h>
#include "includes/libft.h"

static int		base_check(char c, int base)
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
	int		s;
	size_t	num;

	i = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '+' || str[i] == '-') && base == 10)
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	num = 0;
	while (base_check(str[i], base) > 0)
	{
		if (str[i] > 47 && str[i] < 58)
			num = (num * base) + (str[i++] - 48);
		else
			num = (num * base) + (str[i++] - 55);
	}
	return (((int)num * s));
}

int		main(void)
{
	char	s[] = "256";
	int		i;

	print("");
}
