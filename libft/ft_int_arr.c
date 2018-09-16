/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:40:46 by vordynsk          #+#    #+#             */
/*   Updated: 2018/08/07 13:40:49 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_int_arr(int ***arr, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	if (!(*arr = (int **)malloc(sizeof(int *) * y)))
		exit(0);
	while (j < y)
	{
		if (!((*arr)[j] = (int *)malloc(sizeof(int) * x)))
			exit(0);
		i = 0;
		while (i < x)
		{
			(*arr)[j][i] = 0;
			i++;
		}
		j++;
	}
}
