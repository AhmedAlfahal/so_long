/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:29:44 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/01 15:15:29 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_so_long *s)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	s->img->wall, s->map->j * 64, s->map->i * 64);
}

void	draw_space(t_so_long *s)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	s->img->space, s->map->j * 64, s->map->i * 64);
}

void	draw_coin(t_so_long *s)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	s->img->coin, s->map->j * 64, s->map->i * 64);
}

void	draw_player(t_so_long *s)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	s->img->player, s->map->j * 64, s->map->i * 64);
	s->map->p_i = s->map->i;
	s->map->p_j = s->map->j;
}

void	draw_exit(t_so_long *s)
{
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, \
	s->img->exit, s->map->j * 64, s->map->i * 64);
}
