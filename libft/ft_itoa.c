/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:35:26 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/02 15:02:12 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	int			i;
	char		*num;

	i = 1;
	nb = n;
	while ((nb = nb / 10))
		i++;
	nb = n;
	if (n < 0 && (nb = -nb))
		i++;
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i--] = '\0';
	while (i != -1)
	{
		num[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
