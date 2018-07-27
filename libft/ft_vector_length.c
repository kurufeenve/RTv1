/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:21:59 by vordynsk          #+#    #+#             */
/*   Updated: 2018/07/27 13:22:01 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_vector_length(t_vector *v)
{
	v->length = sqrt((v->ex - v->bx) * (v->ex - v->bx) + (v->ey - v->by)\
	* (v->ey - v->by) + (v->ez - v->bz) * (v->ez - v->bz));
}
