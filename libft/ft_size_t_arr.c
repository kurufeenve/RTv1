/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:43:44 by vordynsk          #+#    #+#             */
/*   Updated: 2018/08/08 13:43:48 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		**ft_size_t_arr(int x, int y)
{
	size_t	**arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	arr = (size_t **)malloc(sizeof(size_t *) * y);
	while (j < y)
	{
		arr[j] = (size_t *)malloc(sizeof(size_t) * x);
		j++;
	}
	return (arr);
}
