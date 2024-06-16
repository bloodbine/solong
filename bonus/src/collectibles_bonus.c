/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:10:19 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/08 13:43:17 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_collectibles(t_data *g)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	g->clcount = 0;
	while (++y != g->y)
	{
		while (++x != g->x)
		{
			if (g->map[y][x] == 'C')
				g->clcount++;
		}
		x = 0;
	}
}

void	load_collectibles(t_data *g)
{
	int				count;
	int				x;
	int				y;

	count = 0;
	x = -1;
	y = -1;
	g->pl.collected = 0;
	count_collectibles(g);
	while (++y != g->y && count <= g->clcount)
	{
		while (++x != g->x)
		{
			if (g->map[y][x] == 'C')
			{
				count += 1;
				if (mlx_image_to_window(g->mlx, g->spr[5], x * 32, y * 32) < 0)
					exit_error(g, "Error\nFailed to initialize collectibles\n");
			}
		}
		x = -1;
	}
}

void	check_collect(t_data *g)
{
	mlx_texture_t	*open;
	int				x;
	int				y;
	int				i;

	i = 0;
	while (i <= g->clcount)
	{
		x = g->spr[5]->instances[i].x / 32;
		y = g->spr[5]->instances[i].y / 32;
		if (g->pl.x == x && g->pl.y == y && g->spr[5]->instances[i].enabled)
		{
			g->spr[5]->instances[i].enabled = false;
			g->pl.collected += 1;
		}
		i++;
	}
	if (g->pl.collected == g->clcount)
	{
		open = mlx_load_png("bonus/sprites/open.png");
		mlx_draw_texture(g->spr[3], open, 0, 0);
		mlx_delete_texture(open);
	}
}
