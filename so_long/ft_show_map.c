/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:36:02 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 20:24:57 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_images(t_vars *vars)
{
	vars->images.img_wall = mlx_xpm_file_to_image(vars->mlx, "spr/water.xpm",
			&vars->images.img_width, &vars->images.img_height);
	vars->images.img_floor = mlx_xpm_file_to_image(vars->mlx, "spr/floor.xpm",
			&vars->images.img_width, &vars->images.img_height);
	vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "spr/Ply_r.xpm",
			&vars->images.img_width, &vars->images.img_height);
	vars->images.img_chest = mlx_xpm_file_to_image(vars->mlx, "spr/Chest.xpm",
			&vars->images.img_width, &vars->images.img_height);
	vars->images.img_exit = mlx_xpm_file_to_image(vars->mlx, "spr/exit.xpm",
			&vars->images.img_width, &vars->images.img_height);
	vars->images.img_enemy = mlx_xpm_file_to_image(vars->mlx, "spr/enemy_u.xpm",
			&vars->images.img_width, &vars->images.img_height);
}

void	ft_set_position(t_vars *vars, int i, int j)
{
	if (!vars->player_position_set)
	{
		vars->player_x = i;
		vars->player_y = j;
		vars->player_position_set = 1;
	}
}

void	ft_set_player(t_vars *var, int prev_x, int prev_y)
{
	ft_set_position(var, prev_x, prev_y);
	mlx_put_image_to_window(var->mlx, var->win, var->images.img_floor,
		prev_x * var->images.img_width, prev_y * var->images.img_height);
	mlx_put_image_to_window(var->mlx, var->win, var->images.img_floor,
		var->player_x * var->images.img_width,
		var->player_y * var->images.img_height);
	mlx_put_image_to_window(var->mlx, var->win, var->images.img_ply,
		var->player_x * var->images.img_width,
		var->player_y * var->images.img_height);
}

void	ft_print(char *line, t_vars *var, int j)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(var->mlx, var->win, var->images.img_wall,
				i * var->images.img_width, j * var->images.img_height);
		else if (line[i] == '0')
			mlx_put_image_to_window(var->mlx, var->win, var->images.img_floor,
				i * var->images.img_width, j * var->images.img_height);
		else if (line[i] == 'C')
		{
			mlx_put_image_to_window(var->mlx, var->win, var->images.img_chest,
				i * var->images.img_width, j * var->images.img_height);
			var->collectible++;
		}
		else if (line[i] == 'E')
			mlx_put_image_to_window(var->mlx, var->win, var->images.img_exit,
				i * var->images.img_width, j * var->images.img_height);
		else if (line[i] == 'P')
			ft_set_player(var, i, j);
		ft_print_enemy(line, var, i, j);
		i++;
	}
}

void	ft_show_map(char *argv, t_vars *vars)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	if (!vars->map)
	{
		close(fd);
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		vars->map[j] = line;
		ft_print(line, vars, j);
		line = get_next_line(fd);
		j++;
	}
	vars->map[j] = NULL;
	close(fd);
}
