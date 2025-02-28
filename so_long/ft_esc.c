/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:15:14 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 20:21:42 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	update_player_image(t_vars *var, char *image_path)
{
	if (var->images.img_ply)
		mlx_destroy_image(var->mlx, var->images.img_ply);
	var->images.img_ply = mlx_xpm_file_to_image(var->mlx, image_path,
			&var->images.img_width, &var->images.img_height);
	if (var->is_enemy)
	{
		if (var->images.img_enemy)
			mlx_destroy_image(var->mlx, var->images.img_enemy);
		if (var->moves % 2 == 0)
		{
			var->images.img_enemy = mlx_xpm_file_to_image(var->mlx,
					"spr/enemy_u.xpm",
					&var->images.img_width, &var->images.img_height);
		}
		else
		{
			var->images.img_enemy = mlx_xpm_file_to_image(var->mlx,
					"spr/enemy_d.xpm",
					&var->images.img_width, &var->images.img_height);
		}
		mlx_put_image_to_window(var->mlx, var->win, var->images.img_enemy,
			var->enemy_x * var->images.img_width,
			var->enemy_y * var->images.img_height);
	}
}

void	handle_keycode(int keycode, t_vars *var, int *new_x, int *new_y)
{
	if (keycode == 119 || keycode == 65362)
	{
		update_player_image(var, "spr/Ply_u.xpm");
		(*new_y)--;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		update_player_image(var, "spr/Ply_d.xpm");
		(*new_y)++;
	}
	else if (keycode == 97 || keycode == 65361)
	{
		update_player_image(var, "spr/Ply_l.xpm");
		(*new_x)--;
	}
	else if (keycode == 100 || keycode == 65363)
	{
		update_player_image(var, "spr/Ply_r.xpm");
		(*new_x)++;
	}
}

void	update_map(t_vars *var, int new_x, int new_y)
{
	if (var->map[new_y][new_x] == '0' || var->map[new_y][new_x] == 'C')
	{
		if (var->map[new_y][new_x] == 'C')
			var->collectible--;
		var->map[var->player_y][var->player_x] = '0';
		var->map[new_y][new_x] = 'P';
		var->player_x = new_x;
		var->player_y = new_y;
		var->moves++;
	}
	else if (var->map[new_y][new_x] == 'J')
	{
		var->moves++;
		ft_printf("%s", "You lose\n");
		ft_close(var);
	}
	else if (var->map[new_y][new_x] == 'E' && var->collectible == 0)
	{
		var->moves++;
		ft_printf("%s", "You win\n");
		ft_close(var);
	}
	ft_moves_window(var);
}

int	ft_esc(int keycode, t_vars *var)
{
	int					new_x;
	int					new_y;
	int					prev_x;
	int					prev_y;

	new_x = var->player_x;
	new_y = var->player_y;
	prev_x = var->player_x;
	prev_y = var->player_y;
	if (keycode == 65307)
		return (ft_close(var));
	else
		handle_keycode(keycode, var, &new_x, &new_y);
	update_map(var, new_x, new_y);
	ft_set_player(var, prev_x, prev_y);
	ft_printf("Moves: %d\n", var->moves);
	return (EXIT_SUCCESS);
}
