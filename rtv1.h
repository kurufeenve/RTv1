/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:40:05 by vordynsk          #+#    #+#             */
/*   Updated: 2018/07/03 17:40:08 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1
# define RTV1

# include "libft/includes/libft.h"
# include <OpenCL/opencl.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef	union		u_color
{
	int				color;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_general
{
	void			*init;
	void			*win;
	int				size_x;
	int				size_y;
	void			*img;
	char			*image;
	int				bpp;
	int				val;
	int				ed;
}					t_general;

int					exit_x(void);
int					key_hook(int key, void *ptr);
void				put_pixel(t_general *g, int x, int y, t_color color);
void				pixel_color(t_general *g);

#endif
