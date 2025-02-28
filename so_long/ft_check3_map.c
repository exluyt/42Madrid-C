/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:23:45 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 20:24:36 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_enemy(char *line, t_vars *var, int i, int j)
{
	if (line[i] == 'J')
	{
		var->is_enemy = 1;
		var->enemy_x = i;
		var->enemy_y = j;
		mlx_put_image_to_window(var->mlx, var->win, var->images.img_enemy,
			i * var->images.img_width, j * var->images.img_height);
	}
}

void	ft_moves_window(t_vars *var)
{
	char	*str;
	int		x;
	int		y;
	int		i;
	int		j;

	str = ft_itoa(var->moves);
	x = 10;
	y = 10;
	i = x;
	while (i < x + var->rect_width)
	{
		j = y;
		while (j < y + var->rect_height)
		{
			mlx_pixel_put(var->mlx, var->win, i, j, var->color_bg);
			j++;
		}
		i++;
	}
	mlx_string_put(var->mlx, var->win, x + 5, y + 15, 0x00FFFFFF, "Moves:");
	mlx_string_put(var->mlx, var->win, x + 45, y + 15, 0x00FFFFFF, str);
	free(str);
}

int	ft_all_chr(char **map, t_vars var)
{
	int	i;
	int	j;

	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P'
				&& map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != 'J'
				&& map[j][i] != '\n')
				return (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
