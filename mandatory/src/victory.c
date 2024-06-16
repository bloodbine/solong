/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:58:28 by gpasztor          #+#    #+#             */
/*   Updated: 2023/02/25 15:24:20 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_victory(t_data *g)
{
	if (g->pl.collected == g->clcount)
	{
		if (g->exit.x == g->pl.x && g->exit.y == g->pl.y)
		{
			ft_printf("Victory!");
			mlx_close_window(g->mlx);
		}
	}
}
