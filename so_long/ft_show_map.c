/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:36:02 by akiss             #+#    #+#             */
/*   Updated: 2024/11/01 12:46:26 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_calc_width(char *argv)
{
	int fd;
	char *line;
	int i;
    int width;

	i = 0;
    width = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		line = get_next_line(fd);
		while (line[i] != '\0')
        {   
            if (line[i] == '\n')
            {
                i++;
            }
            width++;
            i++;
        }	
	}
	free(line);
	close(fd);
	return (width - 1);
}

int ft_calc_height(char *argv)
{
	int fd;
	int height;
	char *line;

	height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return height;
}

void	ft_init_images(t_vars *vars)
{
    vars->images.img_wall = mlx_xpm_file_to_image(vars->mlx, "sprites/water.xpm", &vars->images.img_width, &vars->images.img_height);
    vars->images.img_floor = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm", &vars->images.img_width, &vars->images.img_height);
    vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_r.xpm", &vars->images.img_width, &vars->images.img_height);
    vars->images.img_chest = mlx_xpm_file_to_image(vars->mlx, "sprites/Chest.xpm", &vars->images.img_width, &vars->images.img_height);
    vars->images.img_exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm", &vars->images.img_width, &vars->images.img_height);
}

void ft_print(char *line, t_vars *vars, int j)
{
    int i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '1')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_wall, i * vars->images.img_width, j * vars->images.img_height);
        else if (line[i] == '0')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_floor, i * vars->images.img_width, j * vars->images.img_height);
        else if (line[i] == 'C')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_chest, i * vars->images.img_width, j * vars->images.img_height);
        else if (line[i] == 'E')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_exit, i * vars->images.img_width, j * vars->images.img_height);
        else if (line[i] == 'P')
        {
            if (!vars->player_position_set)
            {
                vars->player_x = i;
                vars->player_y = j;
                vars->player_position_set = 1;
            }
            printf("Player position: x = %d, y = %d\n", vars->player_x, vars->player_y);
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_floor, i * vars->images.img_width, j * vars->images.img_height);
            mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_ply, vars->player_x * vars->images.img_width, vars->player_y * vars->images.img_height);
        }
        i++;
    }
}

void ft_show_map(char *argv, t_vars *vars)
{
	int fd;
	char *line;
	int j = 0;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return;
	}
	if (!vars->map)
	{
		write(1, "Error\n", 6);
		close(fd);
		return;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map[j] = line;
		ft_print(line, vars, j);
		j++;
	}
	free(line);
	vars->map[j] = NULL;
	close(fd);
}