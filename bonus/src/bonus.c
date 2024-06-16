/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:26:28 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/08 13:42:42 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

void	print_steps_to_window(t_data *g)
{
	char	*num;

	num = ft_itoa(g->pl.steps);
	mlx_delete_image(g->mlx, g->psteps);
	g->psteps = mlx_put_string(g->mlx, num, 0, 0);
	free(num);
}

void	anim_loop_player(void *param)
{
	static int	wait;
	static int	i;
	t_data		*g;

	g = (t_data *)param;
	if (wait == 15)
	{
		if (g->pl.dir == 'S')
			mlx_draw_texture(g->pl.img, g->pl.txs[0 + i], 0, 0);
		if (g->pl.dir == 'N')
			mlx_draw_texture(g->pl.img, g->pl.txs[3 + i], 0, 0);
		if (g->pl.dir == 'E')
			mlx_draw_texture(g->pl.img, g->pl.txs[6 + i], 0, 0);
		if (g->pl.dir == 'W')
			mlx_draw_texture(g->pl.img, g->pl.txs[9 + i], 0, 0);
		i += 1;
		wait = 0;
	}
	wait += 1;
	if (i == 3)
		i = 0;
}
