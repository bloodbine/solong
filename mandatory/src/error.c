/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:42:49 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/20 13:47:24 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_arg(void)
{
	write(2, "Error\nInvalid argument input\n", 30);
	exit(EXIT_FAILURE);
}

void	check_size(t_data *g, char **map)
{
	if (g->x > 80 && g->y > 44)
	{
		write(2, "Error\nThe map is both too wide and high.\n", 42);
		free(*map);
		exit(EXIT_FAILURE);
	}
	if (g->x > 80)
	{
		write(2, "Error\nThe map is too wide.\n", 28);
		free(*map);
		exit(EXIT_FAILURE);
	}
	if (g->y > 44)
	{
		write(2, "Error\nThe map is too high.\n", 28);
		free(*map);
		exit(EXIT_FAILURE);
	}
	if (g->x < 3 || g->y < 3)
	{
		write(2, "Error\nThe map is too small.\n", 29);
		free(*map);
		exit(EXIT_FAILURE);
	}
}

void	free_map(t_data *g, char **map)
{
	int	y;

	y = -1;
	while (++y != g->y)
		free(map[y]);
	free(map);
}

void	fd_error(char	*mapname)
{
	free(mapname);
	write(2, "Error\nFailed to open file\n", 27);
	exit(EXIT_FAILURE);
}

void	exit_error(t_data *g, char *message)
{
	int	i;

	i = -1;
	free_map(g, g->map);
	if (g->mlx != NULL)
		mlx_terminate(g->mlx);
	while (message[++i] != '\0')
		write(2, &message[i], 1);
	exit(EXIT_FAILURE);
}
