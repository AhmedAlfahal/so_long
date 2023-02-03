/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:38:59 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/02 17:44:46 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_so_long	*s)
{
	if (s->map->map[s->map->p_i - 1][s->map->p_j] == 'E' \
	&& s->map->coin == 0)
		clean_exit(s->map, 8, 1);
	else if (s->map->map[s->map->p_i - 1][s->map->p_j] == 'E' \
	&& s->map->coin != 0)
		write(2, "You have to collect all coins\n", 31);
	else if (s->map->map[s->map->p_i - 1][s->map->p_j] != '1')
	{
		if (s->map->map[s->map->p_i - 1][s->map->p_j] == 'C')
			s->map->coin--;
		s->map->map[s->map->p_i][s->map->p_j] = '0';
		s->map->map[s->map->p_i - 1][s->map->p_j] = 'P';
		draw_map(s);
		ft_printf("[%d]	move so far...\n", ++s->map->moves);
	}
}

void	go_down(t_so_long	*s)
{
	if (s->map->map[s->map->p_i + 1][s->map->p_j] == 'E' \
	&& s->map->coin == 0)
		clean_exit(s->map, 8, 1);
	else if (s->map->map[s->map->p_i + 1][s->map->p_j] == 'E' \
	&& s->map->coin != 0)
		write(2, "You have to collect all coins\n", 31);
	else if (s->map->map[s->map->p_i + 1][s->map->p_j] != '1')
	{
		if (s->map->map[s->map->p_i + 1][s->map->p_j] == 'C')
			s->map->coin--;
		s->map->map[s->map->p_i][s->map->p_j] = '0';
		s->map->map[s->map->p_i + 1][s->map->p_j] = 'P';
		draw_map(s);
		ft_printf("[%d]	move so far...\n", ++s->map->moves);
	}
}

void	go_left(t_so_long	*s)
{
	if (s->map->map[s->map->p_i][s->map->p_j - 1] == 'E' \
	&& s->map->coin == 0)
		clean_exit(s->map, 8, 1);
	else if (s->map->map[s->map->p_i][s->map->p_j - 1] == 'E' \
	&& s->map->coin != 0)
		write(2, "You have to collect all coins\n", 31);
	else if (s->map->map[s->map->p_i][s->map->p_j - 1] != '1')
	{
		if (s->map->map[s->map->p_i][s->map->p_j - 1] == 'C')
			s->map->coin--;
		s->map->map[s->map->p_i][s->map->p_j] = '0';
		s->map->map[s->map->p_i][s->map->p_j - 1] = 'P';
		draw_map(s);
		ft_printf("[%d]	move so far...\n", ++s->map->moves);
	}
}

void	go_right(t_so_long	*s)
{
	if (s->map->map[s->map->p_i][s->map->p_j + 1] == 'E' \
	&& s->map->coin == 0)
		clean_exit(s->map, 8, 1);
	else if (s->map->map[s->map->p_i][s->map->p_j + 1] == 'E' \
	&& s->map->coin != 0)
		write(2, "You have to collect all coins\n", 31);
	else if (s->map->map[s->map->p_i][s->map->p_j + 1] != '1')
	{
		if (s->map->map[s->map->p_i][s->map->p_j + 1] == 'C')
			s->map->coin--;
		s->map->map[s->map->p_i][s->map->p_j] = '0';
		s->map->map[s->map->p_i][s->map->p_j + 1] = 'P';
		draw_map(s);
		ft_printf("[%d]	move so far...\n", ++s->map->moves);
	}
}
