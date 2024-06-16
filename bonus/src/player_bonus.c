/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ->pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:21:34 by gpasztor          #+#    #+#             */
/*   Updated: 2023/02/20 15:13:01 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_vertical(t_data *g, char dir)
{
	if (dir == 'N' && g->map[g->pl.y - 1][g->pl.x] != '1')
	{
		g->pl.dir = 'N';
		g->pl.y -= 1;
		mlx_draw_texture(g->pl.img, g->pl.txs[3], 0, 0);
		g->pl.img->instances[0].y -= 32;
		g->pl.steps += 1;
		print_steps_to_window(g);
		check_collect(g);
		check_victory(g);
	}
	if (dir == 'S' && g->map[g->pl.y + 1][g->pl.x] != '1')
	{
		g->pl.dir = 'S';
		g->pl.y += 1;
		mlx_draw_texture(g->pl.img, g->pl.txs[0], 0, 0);
		g->pl.img->instances[0].y += 32;
		g->pl.steps += 1;
		print_steps_to_window(g);
		check_collect(g);
		check_victory(g);
	}
}

void	player_horizontal(t_data *g, char dir)
{
	if (dir == 'W' && g->map[g->pl.y][g->pl.x - 1] != '1')
	{
		g->pl.dir = 'W';
		g->pl.x -= 1;
		mlx_draw_texture(g->pl.img, g->pl.txs[9], 0, 0);
		g->pl.img->instances[0].x -= 32;
		g->pl.steps += 1;
		print_steps_to_window(g);
		check_collect(g);
		check_victory(g);
	}
	if (dir == 'E' && g->map[g->pl.y][g->pl.x + 1] != '1')
	{
		g->pl.dir = 'E';
		g->pl.x += 1;
		mlx_draw_texture(g->pl.img, g->pl.txs[6], 0, 0);
		g->pl.img->instances[0].x += 32;
		g->pl.steps += 1;
		print_steps_to_window(g);
		check_collect(g);
		check_victory(g);
	}
}

void	player_controls(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			return (mlx_close_window(((t_data *)param)->mlx));
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			player_vertical((t_data *)param, 'N');
			enemy_vertical((t_data *)param, 'N');
		}
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			player_horizontal((t_data *)param, 'W');
			enemy_horizontal((t_data *)param, 'W');
		}
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			player_vertical((t_data *)param, 'S');
			enemy_vertical((t_data *)param, 'S');
		}
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			player_horizontal((t_data *)param, 'E');
			enemy_horizontal((t_data *)param, 'E');
		}
	}
}

void	load_player(t_data *g)
{
	read_character_textures(g);
	if (mlx_image_to_window(g->mlx, g->pl.img, g->pl.x * 32, g->pl.y * 32) < 0)
		exit_error(g, "Failed to load player.");
	g->pl.hp = 3;
	g->pl.steps = 0;
	g->psteps = mlx_put_string(g->mlx, "0", 0, 0);
	g->pl.dir = 'S';
	mlx_loop_hook(g->mlx, &anim_loop_player, g);
	mlx_key_hook(g->mlx, &player_controls, g);
}
