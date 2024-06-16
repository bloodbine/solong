/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:28:18 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/08 11:36:02 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_sprites(t_data *g)
{
	mlx_texture_t	**textures;
	int				count;

	textures = malloc(6 * sizeof(mlx_texture_t *));
	g->spr = malloc(6 * sizeof(mlx_image_t *));
	count = -1;
	textures[0] = mlx_load_png("./mandatory/sprites/tile.png");
	textures[1] = mlx_load_png("./mandatory/sprites/wall.png");
	textures[2] = mlx_load_png("./mandatory/sprites/entrance.png");
	textures[3] = mlx_load_png("./mandatory/sprites/exit.png");
	textures[4] = mlx_load_png("./mandatory/sprites/base.png");
	textures[5] = mlx_load_png("./mandatory/sprites/chest.png");
	while (++count != 6)
	{
		g->spr[count] = mlx_texture_to_image(g->mlx, textures[count]);
		mlx_delete_texture(textures[count]);
	}
	free(textures);
}
