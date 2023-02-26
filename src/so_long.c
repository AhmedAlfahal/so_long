/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:16:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/26 17:57:33 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	uninitialize_imgs(t_so_long *s, t_img *img)
{
	mlx_destroy_image(s->mlx->mlx, img->player);
	mlx_destroy_image(s->mlx->mlx, img->wall);
	mlx_destroy_image(s->mlx->mlx, img->coin);
	mlx_destroy_image(s->mlx->mlx, img->space);
	mlx_destroy_image(s->mlx->mlx, img->exit);
}

static int	destroy_window(t_so_long *s)
{
	uninitialize_imgs(s, s->img);
	mlx_destroy_window(s->mlx->mlx, s->mlx->win);
	free_2d_array(s->map->map);
	free(s->map);
	write(2, "bye\n", 4);
	exit(0);
}

static void	go(t_so_long *s, int x, int y)
{
	if (s->map->map[s->map->p_i + y][s->map->p_j + x] == 'E' \
	&& s->map->coin == 0)
		clean_exit(s->map, 8, 1);
	else if (s->map->map[s->map->p_i + y][s->map->p_j + x] == 'E' \
	&& s->map->coin != 0)
		write(2, "You have to collect all coins\n", 31);
	else if (s->map->map[s->map->p_i + y][s->map->p_j + x] != '1')
	{
		if (s->map->map[s->map->p_i + y][s->map->p_j + x] == 'C')
			s->map->coin--;
		s->map->map[s->map->p_i][s->map->p_j] = '0';
		s->map->map[s->map->p_i + y][s->map->p_j + x] = 'P';
		draw_map(s);
		ft_printf("[%d]	move so far...\n", ++s->map->moves);
	}
}

static int	key(int key_code, t_so_long *s)
{
	if (key_code == 53)
		destroy_window(s);
	else if (key_code == 13)
		go(s, 0, -1);
	else if (key_code == 1)
		go(s, 0, 1);
	else if (key_code == 0)
		go(s, -1, 0);
	else if (key_code == 2)
		go(s, 1, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_so_long	s;
	t_mlx		mlx;
	t_img		img;

	if (ac == 2)
	{
		s.map = reading_map(av[1]);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, \
		s.map->map_width * 64, s.map->map_height * 64, "so_long");
		s.mlx = &mlx;
		initialize_imgs(&s, &img);
		draw_map(&s);
		mlx_hook(s.mlx->win, 2, 0, key, &s);
		mlx_hook(s.mlx->win, 17, 0, destroy_window, &s);
		mlx_loop(s.mlx->mlx);
	}
	return (1);
}
