/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:05 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/26 17:31:16 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	closing_and_freeing(int fd, char *line, int ext)
{
	close(fd);
	free(line);
	if (ext == 1)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

static t_map	*check_map_component(char **mapp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapp[i] != NULL)
	{
		j = 0;
		while (mapp[i][j] != '\0')
		{
			if (mapp[i][j] != '0' && mapp[i][j] != '1' \
			&& mapp[i][j] != 'C' && mapp[i][j] != 'E' && mapp[i][j] != 'P')
			{
				free_2d_array(mapp);
				write(2, "Error\nWrong map commponent\n", 28);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (letting_component_in(mapp));
}

static char	**reading_to2d(char *s, int number_of_lines)
{
	int		fd;
	char	*line;
	char	**mapp;
	int		i;

	mapp = malloc(sizeof(char *) * (number_of_lines + 1));
	if (!mapp)
		return (NULL);
	fd = open(s, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		mapp[i++] = line;
		line = get_next_line(fd);
	}
	mapp[i] = 0;
	close(fd);
	return (mapp);
}

t_map	*reading_map(char *s)
{
	int		fd;
	char	*line;
	size_t	lenn;
	int		number_of_lines;

	number_of_lines = 0;
	fd = open(s, O_RDONLY);
	if (ft_strncmp(s, ".ber", ft_strlen(s) - 4) == 1)
		closing_and_freeing(fd, NULL, 1);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	lenn = ft_strlen(line);
	while (line != NULL)
	{
		if ((lenn > ft_strlen(line) || lenn < ft_strlen(line)) && line != NULL)
			closing_and_freeing(fd, line, 1);
		free(line);
		number_of_lines++;
		line = get_next_line(fd);
	}
	closing_and_freeing(fd, line, 0);
	return (check_map_component(reading_to2d(s, number_of_lines)));
}

void	free_2d_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}
