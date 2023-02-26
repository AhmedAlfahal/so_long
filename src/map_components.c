/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:08:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/26 17:28:53 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	checking_walls(t_map *map, int i, int j)
{
	while (map->map[i] != NULL)
	{
		if (i == 0 || map->map[i + 1] == NULL)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (map->map[i][j] != '1')
					clean_exit(map, 6, 1);
				j++;
			}
		}
		if (map->map[i][0] != '1' || map->map[i][j - 1] != '1')
			clean_exit(map, 6, 1);
		i++;
	}
}

static void	letting_component_in_help(t_map *map, int i, int j)
{
	if (map->map[i][j] == '0')
		map->empty++;
	if (map->map[i][j] == '1')
		map->wall++;
	if (map->map[i][j] != 'C' && map->map[i][j + 1] == '\0' \
	&& map->map[i + 1] == NULL && map->coin == 0)
		clean_exit(map, 2, 1);
	else if (map->map[i][j] == 'C')
		map->coin++;
	else if ((map->map[i][j] == 'P' && map->player > 0) \
	|| (map->map[i][j] != 'P' && map->map[i][j + 1] == '\0' \
	&& map->map[i + 1] == NULL && map->player == 0))
		clean_exit(map, 3, 1);
	else if (map->map[i][j] == 'P')
		map->player++;
	if ((map->map[i][j] == 'E' && map->exit > 0) \
	|| (map->map[i][j] != 'E' && map->map[i][j + 1] == '\0' \
	&& map->map[i + 1] == NULL && map->exit == 0))
		clean_exit(map, 4, 1);
	else if (map->map[i][j] == 'E')
		map->exit++;
}

static t_map	*getting_map_ready(char **mapp)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	map->map = mapp;
	map->i = 0;
	map->j = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->moves = 0;
	map->map_height = 0;
	map->map_width = 0;
	map->coin = 0;
	map->empty = 0;
	map->exit = 0;
	map->player = 0;
	map->wall = 0;
	return (map);
}

t_map	*letting_component_in(char **mapp)
{
	t_map	*map;

	map = getting_map_ready(mapp);
	if (!*mapp)
		clean_exit(map, 1, 1);
	checking_walls(map, map->i, map->j);
	while (mapp[map->i] != NULL)
	{
		map->j = 0;
		while (mapp[map->i][map->j] != '\0')
		{
			letting_component_in_help(map, map->i, map->j);
			if (mapp[map->i][map->j] == 'P')
			{
				map->p_i = map->i;
				map->p_j = map->j;
			}
			map->j++;
		}
		map->i++;
	}
	cloning_2d_array(map);
	validete_path(map, map->p_i, map->p_j);
	checking_vp_output(map);
	return (map);
}

void	clean_exit(t_map *map, int msg, int ex)
{
	if (msg == 1)
		write(2, "Error\nNothing in th map :))))\n", 31);
	if (msg == 2)
		write(2, "Error\nYou have no Coins in your map\n", 37);
	else if (msg == 3)
		write(2, "Error\nYou must have only one player in the map\n", 48);
	else if (msg == 4)
		write(2, "Error\nYou must have only one exit in the map\n", 46);
	else if (msg == 5)
		write(2, "Error\nInvalid Path\n", 20);
	else if (msg == 6)
		write(2, "Error\nthe map is not surrounded by walls\n", 42);
	else if (msg == 7)
		write(2, "bye\n", 4);
	else if (msg == 8)
		ft_printf("GG 😍😍😍😍😍😍😍😍😍😍😍\n");
	else if (msg == 9)
		write(2, "Error\nInvalid Path\n", 20);
	else if (msg == 10)
		write(2, "Error\nOne of the '.xpms' is missing\n", 37);
	free_2d_array(map->map);
	free(map);
	exit(ex);
}
