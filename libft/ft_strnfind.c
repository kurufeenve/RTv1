/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:05:03 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/20 19:05:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnfind(char *haystack, char needle, size_t n)
{
	while (haystack[n] != '\0')
	{
		if (haystack[n] == needle)
			return (n);
		n++;
	}
	return (-1);
}
