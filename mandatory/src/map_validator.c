/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:18:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/01 13:01:07 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_vertical_walls(t_data *g)
{
	int	y;

	y = 0;
	while (++y != g->y)
	{
		if (g->map[y][0] != '1')
			exit_error(g, "Error\nInvalid walls\n");
		if (g->map[y][g->x - 1] != '1')
			exit_error(g, "Error\nInvalid walls\n");
	}
	valid_playability(g, g->pl.x, g->pl.y);
}

void	valid_horizontal_walls(t_data *g)
{
	int	x;

	x = -1;
	while (++x != g->x)
	{
		if (g->map[0][x] != '1')
			exit_error(g, "Error\nInvalid walls\n");
		if (g->map[g->y - 1][x] != '1')
			exit_error(g, "Error\nInvalid walls\n");
	}
	valid_vertical_walls(g);
}

void	valid_shape(t_data *g)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (++y != g->y)
	{
		while (g->map[y][x] != '\0')
			x += 1;
		if (x != g->x)
		{
			free(g->map);
			write(2, "Error\nInvalid shape\n", 21);
			exit(1);
		}
		x = 0;
	}
	valid_horizontal_walls(g);
}

void	valid_required(t_data *g, char type, int x, int y)
{
	int	count;

	count = 0;
	while (++y != g->y)
	{
		while (++x != g->x)
		{
			if (g->map[y][x] == type)
				count++;
		}
		x = -1;
	}
	if (type == 'C' && count == 0)
		exit_error(g, "Error\nTile requirements unfulfilled\n");
	if ((type == 'E' || type == 'P') && count != 1)
		exit_error(g, "Error\nTile requirements unfulfilled\n");
}

void	valid_characters(t_data *g)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y != g->y)
	{
		while (++x != g->x)
		{
			if (!ft_strchr("01CEP\0", g->map[y][x]))
				exit_error(g, "Error\nInvalid tile in map\n");
		}
		x = -1;
	}
	valid_required(g, 'C', -1, -1);
	valid_required(g, 'E', -1, -1);
	valid_required(g, 'P', -1, -1);
	find_start(g);
	find_exit(g);
	valid_shape(g);
}
