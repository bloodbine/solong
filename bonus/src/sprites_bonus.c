/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:28:18 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/08 14:09:30 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_sprites(t_data *g)
{
	mlx_texture_t	**textures;
	int				count;

	textures = malloc(6 * sizeof(mlx_texture_t *));
	g->spr = malloc(6 * sizeof(mlx_image_t *));
	count = -1;
	textures[0] = mlx_load_png("./bonus/sprites/tile.png");
	textures[1] = mlx_load_png("./bonus/sprites/wall.png");
	textures[2] = mlx_load_png("./bonus/sprites/entrance.png");
	textures[3] = mlx_load_png("./bonus/sprites/exit.png");
	textures[4] = mlx_load_png("./bonus/sprites/base.png");
	textures[5] = mlx_load_png("./bonus/sprites/chest.png");
	while (++count != 6)
	{
		g->spr[count] = mlx_texture_to_image(g->mlx, textures[count]);
		mlx_delete_texture(textures[count]);
	}
	free(textures);
}

void	read_character_textures(t_data *g)
{
	g->pl.txs = malloc(12 * sizeof(mlx_texture_t *));
	g->pl.txs[0] = mlx_load_png("./bonus/sprites/char/S1.png");
	g->pl.txs[1] = mlx_load_png("./bonus/sprites/char/S2.png");
	g->pl.txs[2] = mlx_load_png("./bonus/sprites/char/S3.png");
	g->pl.txs[3] = mlx_load_png("./bonus/sprites/char/N1.png");
	g->pl.txs[4] = mlx_load_png("./bonus/sprites/char/N2.png");
	g->pl.txs[5] = mlx_load_png("./bonus/sprites/char/N3.png");
	g->pl.txs[6] = mlx_load_png("./bonus/sprites/char/E1.png");
	g->pl.txs[7] = mlx_load_png("./bonus/sprites/char/E2.png");
	g->pl.txs[8] = mlx_load_png("./bonus/sprites/char/E3.png");
	g->pl.txs[9] = mlx_load_png("./bonus/sprites/char/W1.png");
	g->pl.txs[10] = mlx_load_png("./bonus/sprites/char/W2.png");
	g->pl.txs[11] = mlx_load_png("./bonus/sprites/char/W3.png");
	g->pl.img = mlx_texture_to_image(g->mlx, g->pl.txs[0]);
}

void	read_enemy_textures(t_data *g)
{
	g->el.txs = malloc(12 * sizeof(mlx_texture_t *));
	g->el.txs[0] = mlx_load_png("./bonus/sprites/enemy/S1.png");
	g->el.txs[1] = mlx_load_png("./bonus/sprites/enemy/S2.png");
	g->el.txs[2] = mlx_load_png("./bonus/sprites/enemy/S3.png");
	g->el.txs[3] = mlx_load_png("./bonus/sprites/enemy/N1.png");
	g->el.txs[4] = mlx_load_png("./bonus/sprites/enemy/N2.png");
	g->el.txs[5] = mlx_load_png("./bonus/sprites/enemy/N3.png");
	g->el.txs[6] = mlx_load_png("./bonus/sprites/enemy/E1.png");
	g->el.txs[7] = mlx_load_png("./bonus/sprites/enemy/E2.png");
	g->el.txs[8] = mlx_load_png("./bonus/sprites/enemy/E3.png");
	g->el.txs[9] = mlx_load_png("./bonus/sprites/enemy/W1.png");
	g->el.txs[10] = mlx_load_png("./bonus/sprites/enemy/W2.png");
	g->el.txs[11] = mlx_load_png("./bonus/sprites/enemy/W3.png");
	g->el.img = mlx_texture_to_image(g->mlx, g->el.txs[0]);
}

void	free_player_textures(t_data *g)
{
	int	i;

	i = -1;
	while (++i != 12)
		mlx_delete_texture(g->pl.txs[i]);
	free(g->pl.txs);
}

void	free_enemy_textures(t_data *g)
{
	int	i;

	i = -1;
	while (++i != 12)
		mlx_delete_texture(g->el.txs[i]);
	free(g->el.txs);
}
