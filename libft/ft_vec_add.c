/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:26:02 by vordynsk          #+#    #+#             */
/*   Updated: 2018/07/27 20:26:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_vec_add(t_vector v1, t_vector v2, t_vector *res)
{
	if (v1.bx == v2.bx && v1.by == v2.by && v1.bz == v2.bz)
	{
		res->bx = v1.bx;
		res->by = v1.by;
		res->bz = v1.bz;
		res->ex = v1.ex + v2.ex;
		res->ey = v1.ey + v2.ey;
		res->ez = v1.ez + v2.ez;
		res->length = 0;
		return (1);
	}
	else
		return (0);
}
