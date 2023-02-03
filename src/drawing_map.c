/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:22:33 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/02 17:56:44 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_map(t_so_long *s)
{
	while (s->map->map[s->map->i])
	{
		s->map->j = 0;
		while (s->map->map[s->map->i][s->map->j])
		{
			if (s->map->map[s->map->i][s->map->j] == '1')
				draw_wall(s);
			else if (s->map->map[s->map->i][s->map->j] == '0')
				draw_space(s);
			else if (s->map->map[s->map->i][s->map->j] == 'C')
				draw_coin(s);
			else if (s->map->map[s->map->i][s->map->j] == 'P')
				draw_player(s);
			else if (s->map->map[s->map->i][s->map->j] == 'E')
				draw_exit(s);
			s->map->j++;
		}
		s->map->i++;
	}
	s->map->i = 0;
	s->map->j = 0;
}

void	initialize_imgs(t_so_long *s, t_img *img)
{
	int	w;

	w = 64;
	img->player = mlx_xpm_file_to_image(s->mlx->mlx, "./xpms/plyr.xpm", &w, &w);
	img->wall = mlx_xpm_file_to_image(s->mlx->mlx, "./xpms/wall.xpm", &w, &w);
	img->coin = mlx_xpm_file_to_image(s->mlx->mlx, "./xpms/coin.xpm", &w, &w);
	img->space = mlx_xpm_file_to_image(s->mlx->mlx, "./xpms/space.xpm", &w, &w);
	img->exit = mlx_xpm_file_to_image(s->mlx->mlx, "./xpms/exit.xpm", &w, &w);
	s->img = img;
	if (img->coin == NULL || img->exit == NULL \
	|| img->player == NULL || img->wall == NULL || img->space == NULL)
		clean_exit(s->map, 10, 1);
}

void	uninitialize_imgs(t_so_long *s, t_img *img)
{
	mlx_destroy_image(s->mlx->mlx, img->player);
	mlx_destroy_image(s->mlx->mlx, img->wall);
	mlx_destroy_image(s->mlx->mlx, img->coin);
	mlx_destroy_image(s->mlx->mlx, img->space);
	mlx_destroy_image(s->mlx->mlx, img->exit);
}
