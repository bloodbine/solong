/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:04:07 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/20 13:42:51 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	anim_loop_enemy(void *param)
{
	static int	wait;
	static int	i;
	t_data		*g;

	g = (t_data *)param;
	if (wait == 15)
	{
		if (g->el.dir == 'S')
			mlx_draw_texture(g->el.img, g->el.txs[0 + i], 0, 0);
		if (g->el.dir == 'N')
			mlx_draw_texture(g->el.img, g->el.txs[3 + i], 0, 0);
		if (g->el.dir == 'E')
			mlx_draw_texture(g->el.img, g->el.txs[6 + i], 0, 0);
		if (g->el.dir == 'W')
			mlx_draw_texture(g->el.img, g->el.txs[9 + i], 0, 0);
		i += 1;
		wait = 0;
	}
	wait += 1;
	if (i == 3)
		i = 0;
}

void	load_health(t_data *g)
{
	mlx_texture_t	*hptexture;

	hptexture = mlx_load_png("./bonus/sprites/heart1.png");
	g->health = mlx_texture_to_image(g->mlx, hptexture);
	mlx_image_to_window(g->mlx, g->health, 0, (g->y - 1) * 32);
	mlx_image_to_window(g->mlx, g->health, 32, (g->y - 1) * 32);
	mlx_image_to_window(g->mlx, g->health, 64, (g->y - 1) * 32);
	mlx_delete_texture(hptexture);
}

void	load_enemies(t_data *g)
{
	int	x;
	int	y;

	read_enemy_textures(g);
	g->ecount = 0;
	x = -1;
	y = -1;
	while (++y != g->y)
	{
		while (++x != g->x)
		{
			if (g->map[y][x] == 'N')
			{
				mlx_image_to_window(g->mlx, g->el.img, x * 32, y * 32);
				g->ecount += 1;
			}
		}
		x = -1;
	}
	g->el.dir = 'S';
	load_health(g);
	mlx_loop_hook(g->mlx, &anim_loop_enemy, g);
}

void	check_enemy(t_data *g)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	while (i < g->ecount)
	{
		x = g->el.img->instances[i].x / 32;
		y = g->el.img->instances[i].y / 32;
		if (g->pl.x == x && g->pl.y == y && g->el.img->instances[i].enabled)
		{
			g->el.img->instances[i].enabled = false;
			g->pl.hp -= 1;
			g->health->instances[g->pl.hp].enabled = false;
		}
		i++;
	}
	check_defeat(g);
}

int	check_em(t_data *g, int x, int y)
{
	int	i;

	i = 0;
	x = x * 32;
	y = y * 32;
	while (i != g->ecount)
	{
		if (g->el.img->instances[i].x == x && g->el.img->instances[i].y == y)
			return (1);
		i++;
	}
	return (0);
}
