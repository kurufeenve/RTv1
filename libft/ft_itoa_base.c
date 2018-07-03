/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:43:06 by vordynsk          #+#    #+#             */
/*   Updated: 2018/04/20 16:43:08 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa_base(int n, int base)
{
	long int	nb;
	int			i;
	char		*num;
	char		buff[17];

	i = 1;
	nb = n;
	ft_strcpy(buff, "0123456789ABCDEF");
	while ((nb = nb / base))
		i++;
	nb = n;
	if (n < 0 && (nb = -nb))
		i++;
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i--] = '\0';
	while (i != -1)
	{
		num[i--] = buff[nb % base];
		nb = nb / base;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
