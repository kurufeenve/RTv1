/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:13:49 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/05 17:15:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf_dest;
	unsigned char	*buf_src;

	i = 0;
	buf_src = (unsigned char *)src;
	buf_dest = (unsigned char *)dest;
	while (i < n)
	{
		buf_dest[i] = buf_src[i];
		if (buf_dest[i] == (unsigned char)c)
			return ((dest + i + 1));
		i++;
	}
	return (NULL);
}
