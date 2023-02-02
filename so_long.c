/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:16:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/02 17:59:22 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	key(int key_code, t_so_long *s)
{
	if (key_code == 53)
		destroy_window(s);
	else if (key_code == 13)
		go_up(s);
	else if (key_code == 1)
		go_down(s);
	else if (key_code == 0)
		go_left(s);
	else if (key_code == 2)
		go_right(s);
	return (0);
}

int	destroy_window(t_so_long *s)
{
	uninitialize_imgs(s, s->img);
	mlx_destroy_window(s->mlx->mlx, s->mlx->win);
	free_2d_array(s->map->map);
	free(s->map);
	write(2, "bye\n", 4);
	exit(0);
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
