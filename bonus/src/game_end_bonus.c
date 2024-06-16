/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:58:28 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/09 13:01:12 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_victory(t_data *g)
{
	if (g->pl.collected == g->clcount)
	{
		if (g->exit.x == g->pl.x && g->exit.y == g->pl.y)
		{
			ft_printf("Victory!\n");
			mlx_close_window(g->mlx);
		}
	}
}

void	check_defeat(t_data *g)
{
	if (g->pl.hp <= 0)
	{
		ft_printf("You Died!\n");
		mlx_terminate(g->mlx);
		free_map(g, g->map);
		free_player_textures(g);
		free_enemy_textures(g);
		exit(0);
	}
}
