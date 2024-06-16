/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playability_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:19:12 by gpasztor          #+#    #+#             */
/*   Updated: 2023/02/26 09:39:19 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_map_to_flood(t_data *g)
{
	int	y;

	y = -1;
	g->flood_map = malloc(g->y * sizeof(char *));
	while (++y != g->y)
		g->flood_map[y] = ft_strdup(g->map[y]);
}

void	valid_playability(t_data *g, int x, int y)
{
	g->flood_map[y][x] = 'X';
	if (g->flood_map[y][x - 1] != 'X' && g->flood_map[y][x - 1] != '1')
		valid_playability(g, x - 1, y);
	if (g->flood_map[y][x + 1] != 'X' && g->flood_map[y][x + 1] != '1')
		valid_playability(g, x + 1, y);
	if (g->flood_map[y - 1][x] != 'X' && g->flood_map[y - 1][x] != '1')
		valid_playability(g, x, y - 1);
	if (g->flood_map[y + 1][x] != 'X' && g->flood_map[y + 1][x] != '1')
		valid_playability(g, x, y + 1);
}

void	check_flood(t_data *g)
{
	int	i;

	i = -1;
	while (++i != g->y)
	{
		if (ft_strchr(g->flood_map[i], 'E') || ft_strchr(g->flood_map[i], 'C'))
		{
			free_map(g, g->flood_map);
			exit_error(g, "Error\nMap unplayable.\n");
		}
	}
	free_map(g, g->flood_map);
}

void	find_start(t_data *g)
{
	g->pl.y = -1;
	while (++g->pl.y != g->y)
	{
		g->pl.x = -1;
		while (++g->pl.x != g->x)
		{
			if (g->map[g->pl.y][g->pl.x] == 'P')
				return ;
		}
	}
}

void	find_exit(t_data *g)
{
	g->exit.y = -1;
	while (++g->exit.y != g->y)
	{
		g->exit.x = -1;
		while (++g->exit.x != g->x)
		{
			if (g->map[g->exit.y][g->exit.x] == 'E')
				return ;
		}
	}
}
