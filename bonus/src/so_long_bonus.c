/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/22 11:03:28 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_data			gamedata;
	char			*map;

	if (argc != 2 || ft_strlen(argv[1]) == 0)
		invalid_arg();
	map = read_map(argv[1], &gamedata.x, &gamedata.y);
	check_size(&gamedata, &map);
	gamedata.map = ft_split(map, '\n');
	gamedata.mlx = NULL;
	gamedata.el.txs = NULL;
	gamedata.pl.txs = NULL;
	copy_map_to_flood(&gamedata);
	valid_characters(&gamedata);
	check_flood(&gamedata);
	gamedata.mlx = mlx_init(gamedata.x * 32, gamedata.y * 32, "so_long", false);
	read_sprites(&gamedata);
	load_map(&gamedata);
	load_collectibles(&gamedata);
	load_enemies(&gamedata);
	load_player(&gamedata);
	mlx_loop(gamedata.mlx);
	mlx_terminate(gamedata.mlx);
	free_player_textures(&gamedata);
	free_enemy_textures(&gamedata);
	return (free_map(&gamedata, gamedata.map), EXIT_SUCCESS);
}
