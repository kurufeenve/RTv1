/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:24:14 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/13 19:24:17 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printarr(int **arr, size_t j)
{
	size_t	n;
	size_t	g;

	if (arr == NULL)
		return ;
	n = 0;
	while (arr[n])
	{
		g = 0;
		while (g < j)
			ft_putnbr(arr[n][g++]);
		n++;
	}
}
