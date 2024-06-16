/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:19:49 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/20 13:47:30 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 720
# define HEIGHT 480
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include "../../lib/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

# ifndef PLAYER_H
#  define PLAYER_H

typedef struct s_player
{
	mlx_image_t		*img;
	int				collected;
	int				steps;
	int				x;
	int				y;
}					t_player;
# endif

# ifndef EXIT_H
#  define EXIT_H

typedef struct s_exit
{
	int				x;
	int				y;
}					t_exit;
# endif

# ifndef DATA_H
#  define DATA_H

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	**spr;
	t_player	pl;
	t_exit		exit;
	char		**map;
	char		**flood_map;
	int			clcount;
	int			x;
	int			y;
}				t_data;
# endif

void		valid_playability(t_data *g, int x, int y);
char		*read_map(char *mapname, int *x, int *y);
void		exit_error(t_data *g, char *message);
void		check_size(t_data *g, char **map);
void		free_map(t_data *g, char **map);
void		load_collectibles(t_data *g);
void		copy_map_to_flood(t_data *g);
void		valid_characters(t_data *g);
void		fd_error(char	*mapname);
void		check_collect(t_data *g);
void		check_victory(t_data *g);
void		read_sprites(t_data *g);
void		check_flood(t_data *g);
void		load_player(t_data *g);
void		find_start(t_data *g);
void		find_exit(t_data *g);
void		load_map(t_data *g);
void		invalid_arg(void);

#endif