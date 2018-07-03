/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newarrtozero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:38:05 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/13 19:38:07 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		**ft_newarrtozero(size_t i, size_t j)
{
	size_t		n;
	size_t		g;
	int			**arr;

	n = 0;
	if (!(arr = (int **)malloc(sizeof(int *) * (i + 1))))
		return (NULL);
	arr[i] = NULL;
	while (n < i)
	{
		if (!(arr[n] = (int *)malloc(sizeof(int) * j)))
			return (NULL);
		g = 0;
		while (g < j)
			arr[n][g++] = 0;
		n++;
	}
	return (arr);
}
