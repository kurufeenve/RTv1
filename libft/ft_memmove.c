/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:47:23 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/05 18:47:27 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, void const *src, size_t len)
{
	unsigned char const	*buf_src;
	unsigned char		*buf_dest;

	if (src < dest)
	{
		buf_src = (unsigned char *)src;
		buf_dest = (unsigned char *)dest;
		while (len--)
			buf_dest[len] = buf_src[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
