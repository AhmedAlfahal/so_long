/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:15:58 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/02 17:43:38 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"libft/libft.h"
# include"ft_printf/ft_printf.h"
# include"get_next_line/get_next_line.h"
# include "mlx/mlx.h"

# include<unistd.h>
# include<fcntl.h>

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*player;
}			t_mlx;

typedef struct img
{
	void	*player;
	void	*wall;
	void	*space;
	void	*coin;
	void	*exit;
}			t_img;

typedef struct map
{
	char	**map;
	char	**vp;
	int		i;
	int		j;
	int		map_width;
	int		map_height;
	int		moves;
	int		coin;
	int		p_i;
	int		p_j;
	int		wall;
	int		empty;
	int		player;
	int		exit;
	int		c_count;
	int		e_count;
}					t_map;

typedef struct so_long
{
	struct mlx		*mlx;
	struct img		*img;
	struct map		*map;
}			t_so_long;

/******************************Free & Error*****************************/

void	clean_exit(t_map *map, int msg, int ex);
void	free_2d_array(char **map);
void	closing_and_freeing(int fd, char *line, int ext);

/******************************Parsing Map******************************/

t_map	*reading_map(char *s);
t_map	*check_map_component(char **mapp);
t_map	*letting_component_in(char **mapp);
t_map	*getting_map_ready(char **map);
char	**reading_to2d(char *s, int number_of_lines);
void	checking_walls(t_map *map, int i, int j);
void	letting_component_in_help(t_map *map, int i, int j);

/******************************Map Drawing*******************************/

int		destroy_window(t_so_long *s);
void	initialize_imgs(t_so_long *s, t_img *img);
void	uninitialize_imgs(t_so_long *s, t_img *img);
void	draw_map(t_so_long *s);
void	draw_wall(t_so_long *s);
void	draw_space(t_so_long *s);
void	draw_coin(t_so_long *s);
void	draw_player(t_so_long *s);
void	draw_exit(t_so_long *s);

/******************************Moving Player*******************************/

void	go_up(t_so_long	*s);
void	go_down(t_so_long	*s);
void	go_left(t_so_long	*s);
void	go_right(t_so_long	*s);

/******************************Valid Path**********************************/

void	cloning_2d_array(t_map *map);
void	validete_path(t_map *map, int i, int j);
void	checking_vp_output(t_map *map);

#endif