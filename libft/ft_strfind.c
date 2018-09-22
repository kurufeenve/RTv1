/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:38:30 by vordynsk          #+#    #+#             */
/*   Updated: 2018/09/20 18:38:33 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strfind(char *haystack, char needle)
{
	int		i;

	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}
