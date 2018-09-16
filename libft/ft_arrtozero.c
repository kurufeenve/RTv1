/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtozero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:39:16 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/15 19:01:07 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		**ft_arrtozero(int **arr, size_t j)
{
	size_t	n;
	size_t	g;

	n = 0;
	while (arr[n] != NULL)
	{
		g = 0;
		while (g < j)
			arr[n][g++] = 0;
		n++;
	}
	return (arr);
}
