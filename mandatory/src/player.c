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

#include "so_long.h"

void	player_vertical(t_data *g, char dir)
{
	if (dir == 'N' && g->map[g->pl.y - 1][g->pl.x] != '1')
	{
		g->pl.y -= 1;
		g->pl.img->instances[0].y -= 32;
		g->pl.steps += 1;
		ft_printf("Step count: %d\n", g->pl.steps);
		check_collect(g);
		check_victory(g);
	}
	if (dir == 'S' && g->map[g->pl.y + 1][g->pl.x] != '1')
	{
		g->pl.y += 1;
		g->pl.img->instances[0].y += 32;
		g->pl.steps += 1;
		ft_printf("Step count: %d\n", g->pl.steps);
		check_collect(g);
		check_victory(g);
	}
}

void	player_horizontal(t_data *g, char dir)
{
	if (dir == 'W' && g->map[g->pl.y][g->pl.x - 1] != '1')
	{
		g->pl.x -= 1;
		g->pl.img->instances[0].x -= 32;
		g->pl.steps += 1;
		ft_printf("Step count: %d\n", g->pl.steps);
		check_collect(g);
		check_victory(g);
	}
	if (dir == 'E' && g->map[g->pl.y][g->pl.x + 1] != '1')
	{
		g->pl.x += 1;
		g->pl.img->instances[0].x += 32;
		g->pl.steps += 1;
		ft_printf("Step count: %d\n", g->pl.steps);
		check_collect(g);
		check_victory(g);
	}
}

void	player_controls(mlx_key_data_t keydata, void *param)
{
	t_data	*g;

	g = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			return (mlx_close_window(g->mlx));
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			player_vertical(g, 'N');
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			player_horizontal(g, 'W');
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			player_vertical(g, 'S');
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			player_horizontal(g, 'E');
	}
}

void	load_player(t_data *g)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./mandatory/sprites/character.png");
	g->pl.img = mlx_texture_to_image(g->mlx, texture);
	mlx_delete_texture(texture);
	if (mlx_image_to_window(g->mlx, g->pl.img, g->pl.x * 32, g->pl.y * 32) < 0)
		exit_error(g, "Failed to load player.");
	g->pl.steps = 0;
	mlx_key_hook(g->mlx, &player_controls, g);
}
