/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:35:27 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/20 13:42:28 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_vertical(t_data *g, char dir)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i != g->ecount)
	{
		x = g->el.img->instances[i].x / 32;
		y = g->el.img->instances[i].y / 32;
		if (dir == 'N' && g->map[y - 1][x] != '1' && check_em(g, x, y - 1) == 0)
		{
			g->el.dir = 'N';
			mlx_draw_texture(g->el.img, g->el.txs[3], 0, 0);
			g->el.img->instances[i].y -= 32;
		}
		if (dir == 'S' && g->map[y + 1][x] != '1' && check_em(g, x, y + 1) == 0)
		{
			g->el.dir = 'S';
			mlx_draw_texture(g->el.img, g->el.txs[0], 0, 0);
			g->el.img->instances[i].y += 32;
		}
	}
	check_enemy(g);
}

void	enemy_horizontal(t_data *g, char dir)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i != g->ecount)
	{
		x = g->el.img->instances[i].x / 32;
		y = g->el.img->instances[i].y / 32;
		if (dir == 'W' && g->map[y][x - 1] != '1' && check_em(g, x - 1, y) == 0)
		{
			g->el.dir = 'W';
			mlx_draw_texture(g->el.img, g->el.txs[9], 0, 0);
			g->el.img->instances[i].x -= 32;
		}
		if (dir == 'E' && g->map[y][x + 1] != '1' && check_em(g, x + 1, y) == 0)
		{
			g->el.dir = 'E';
			mlx_draw_texture(g->el.img, g->el.txs[6], 0, 0);
			g->el.img->instances[i].x += 32;
		}
	}
	check_enemy(g);
}
