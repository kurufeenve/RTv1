/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:24:02 by vordynsk          #+#    #+#             */
/*   Updated: 2017/12/20 18:24:03 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_realloc(char *str, size_t size)
{
	char	*new_str;
	size_t	len;
	size_t	sum;

	if (str == NULL)
		return (ft_strnew(size));
	len = ft_strlen(str);
	sum = len + size;
	if (!(new_str = ft_strnew(sum)))
		return (NULL);
	new_str = (char *)ft_memcpy(new_str, str, len);
	ft_strdel(&str);
	return (new_str);
}
