/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:15:08 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/08 18:15:11 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(char const *str)
{
	int		i;
	int		s;
	size_t	num;

	i = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	num = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		num = (num * 10) + (str[i++] - 48);
		if (s > 0 && num > 922337203685477580)
			return (-1);
		if (s < 0 && num > 922337203685477580)
			return (0);
	}
	return (((int)num * s));
}
