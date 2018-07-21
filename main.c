/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:39:55 by vordynsk          #+#    #+#             */
/*   Updated: 2018/07/03 17:39:57 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char** argv)
{
	t_general	g;

	g.size_x = 1000;
	g.size_y = 1000;
	if ((g.init = mlx_init()) == NULL ||
		(g.win = mlx_new_window(g.init,
		g.size_x, g.size_y, "test")) == NULL || (g.img =
		mlx_new_image(g.init, g.size_x, g.size_y)) == NULL ||
		(g.image = mlx_get_data_addr(g.img, &g.bpp, &g.val,
		&g.ed)) == NULL)
		return (0);
	pixel_color(&g);
	mlx_put_image_to_window(g.init, g.win, g.img, 0, 0);
	mlx_hook(g.win, 17, 1L << 17, exit_x, NULL);
	mlx_hook(g.win, 2, 5, key_hook, &g);
	mlx_loop(g.init);
	return (0);
}

void	put_pixel(t_general *g, int x, int y, t_color color)
{
	g->image[y * g->val + 4 * x] = color.channel[0];
	g->image[y * g->val + 4 * x + 1] = color.channel[1];
	g->image[y * g->val + 4 * x + 2] = color.channel[2];
}

int		exit_x(void)
{
	system("leaks RTv1");
	exit(1);
}

int		key_hook(int key, void *ptr)
{
	t_general	*g;

	g = ptr;
	if (key == 53)
	{
		system("leaks RTv1");
		exit(0);
	}
	return (0);
}

void	pixel_color(t_general *g)
{
	t_color	col;
	int		y;
	int		x;

	col.color = 0xFFFFFF;
	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			put_pixel(g, x, y, col);
			x++;
		}
		y++;
	}
}