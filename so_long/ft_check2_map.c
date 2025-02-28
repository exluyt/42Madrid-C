/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:07:51 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 19:11:04 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
			{
				i--;
				free(map_copy[i]);
			}
			return (free(map_copy), NULL);
		}
		i++;
	}
	return (map_copy[height] = NULL, map_copy);
}

int	is_valid_position(t_vars *var, int x, int y, char **visited)
{
	return (x >= 0 && x < var->width && y >= 0 && y < var->height
		&& var->map[y][x] != '1' && var->map[y][x] != 'J'
		&& visited[y][x] != 'f');
}

int	flood_fill(t_vars *var, int x, int y, char **visited)
{
	if (!is_valid_position(var, x, y, visited))
		return (EXIT_SUCCESS);
	if (var->map[y][x] == 'E')
		return (EXIT_FAILURE);
	visited[y][x] = 'f';
	if (flood_fill(var, x + 1, y, visited)
		|| flood_fill(var, x - 1, y, visited)
		|| flood_fill(var, x, y + 1, visited)
		|| flood_fill(var, x, y - 1, visited))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_solvable(char **map, t_vars var)
{
	char	**map_copy;
	int		result;
	int		i;

	map_copy = copy_map(map, var.height);
	if (!map_copy)
		return (EXIT_FAILURE);
	result = flood_fill(&var, var.player_x, var.player_y, map_copy);
	i = 0;
	while (i < var.height)
	{
		free(map_copy[i]);
		i++;
	}
	if (result)
		return (free(map_copy), EXIT_SUCCESS);
	else
		return (free(map_copy), EXIT_FAILURE);
}

int	ft_so_long(char **map, t_vars var)
{
	int		j;
	size_t	line_length;

	if (!map || !map[0])
		return (EXIT_FAILURE);
	line_length = ft_strlen(map[0]);
	j = 1;
	while (j < var.height - 1)
	{
		if (ft_strlen(map[j]) != line_length)
			return (EXIT_FAILURE);
		j++;
	}
	if (ft_strlen(map[var.height - 1]) != line_length - 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
