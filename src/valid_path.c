/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:12:56 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/02 17:45:02 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validete_path(t_map *map, int i, int j)
{
	if (map->vp[i][j] == 'E')
		map->e_count++;
	if (map->vp[i][j] == '1' || map->vp[i][j] == 'X' \
	|| map->vp[i][j] == 'E')
		return ;
	if (map->vp[i][j] == 'C')
		map->c_count++;
	map->vp[i][j] = 'X';
	validete_path(map, i, j - 1);
	validete_path(map, i, j + 1);
	validete_path(map, i - 1, j);
	validete_path(map, i + 1, j);
}

void	cloning_2d_array(t_map *map)
{
	map->map_height = map->i;
	map->map_width = map->j;
	map->i = 0;
	map->j = 0;
	map->vp = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->vp)
		return ;
	while (map->map[map->i])
	{
		map->vp[map->i] = cut(map->map[map->i], 0, ft_strlen(map->map[map->i]));
		map->i++;
	}
	map->vp[map->i] = NULL;
	map->i = 0;
	map->j = 0;
}

void	checking_vp_output(t_map *map)
{
	free_2d_array(map->vp);
	if (map->c_count == map->coin && map->e_count >= 1)
		return ;
	else
		clean_exit(map, 9, 1);
}
