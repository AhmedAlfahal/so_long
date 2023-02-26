/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:22:33 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/26 17:57:25 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	draw_xpm(t_so_long *s, void *xpm, int msg)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	xpm, s->map->j * 64, s->map->i * 64);
	if (msg == 1)
	{
		s->map->p_i = s->map->i;
		s->map->p_j = s->map->j;
	}
}

void	draw_map(t_so_long *s)
{
	while (s->map->map[s->map->i])
	{
		s->map->j = 0;
		while (s->map->map[s->map->i][s->map->j])
		{
			if (s->map->map[s->map->i][s->map->j] == '1')
				draw_xpm(s, s->img->wall, 0);
			else if (s->map->map[s->map->i][s->map->j] == '0')
				draw_xpm(s, s->img->space, 0);
			else if (s->map->map[s->map->i][s->map->j] == 'C')
				draw_xpm(s, s->img->coin, 0);
			else if (s->map->map[s->map->i][s->map->j] == 'P')
				draw_xpm(s, s->img->player, 1);
			else if (s->map->map[s->map->i][s->map->j] == 'E')
				draw_xpm(s, s->img->exit, 0);
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
