/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:35:59 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/01 15:14:51 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_extension(char *mapname)
{
	int	i;

	i = 0;
	while (mapname[i] != '\0')
		i++;
	if ((mapname[i - 1] != 'r' || mapname[i - 2] != 'e') && i > 4)
	{
		if (mapname[i - 3] != 'b' || mapname[i - 4] != '.')
		{
			write(2, "Error\nInvalid map file name or extension\n", 42);
			exit(1);
		}
	}
}

char	*map_join(char *s1, char *s2)
{
	char	*nstring;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		nstring = ft_strdup(s2);
		return (free(s2), nstring);
	}
	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstring)
		return (NULL);
	while (s1[++i])
		nstring[i] = s1[i];
	while (s2[++j])
	{
		nstring[i] = s2[j];
		i++;
	}
	nstring[i] = '\0';
	return (free(s1), free(s2), nstring);
}

char	*read_map(char *mapname, int *x, int *y)
{
	char	*map;
	char	*line;
	int		fd;

	check_extension(mapname);
	mapname = ft_strjoin("bonus/maps/", mapname);
	fd = open(mapname, O_RDONLY);
	*x = -1;
	*y = 0;
	if (fd == -1)
		fd_error(mapname);
	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = map_join(map, line);
		line = get_next_line(fd);
	}
	while (map[++*x])
	{
		if (map[*x] == '\n' || map[*x + 1] == '\0')
			*y += 1;
	}
	*x /= *y;
	return (free(mapname), free(line), close(fd), map);
}

void	load_map(t_data *g)
{
	int	status;
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y != g->y)
	{
		x = -1;
		while (++x != g->x)
		{
			if (g->map[y][x] == '0' || g->map[y][x] == 'N')
				status = mlx_image_to_window(g->mlx, g->spr[0], x * 32, y * 32);
			if (g->map[y][x] == 'P')
				status = mlx_image_to_window(g->mlx, g->spr[2], x * 32, y * 32);
			if (g->map[y][x] == 'E')
				status = mlx_image_to_window(g->mlx, g->spr[3], x * 32, y * 32);
			if (g->map[y][x] == 'C')
				status = mlx_image_to_window(g->mlx, g->spr[4], x * 32, y * 32);
			if (g->map[y][x] == '1')
				status = mlx_image_to_window(g->mlx, g->spr[1], x * 32, y * 32);
			if (status == -1)
				exit_error(g, "Error\nFailed to load map\n");
		}
	}
}
