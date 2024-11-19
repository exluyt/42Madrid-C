/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:15:14 by akiss             #+#    #+#             */
/*   Updated: 2024/11/19 12:50:27 by akiss            ###   ########.fr       */
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
	if (var->map[new_y][new_x] == '0')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[new_y][new_x] = 'P';
		var->player_x = new_x;
		var->player_y = new_y;
		var->moves++;
	}
	else if (var->map[new_y][new_x] == 'C')
	{
		var->map[var->player_y][var->player_x] = '0';
		var->map[new_y][new_x] = 'P';
		var->player_x = new_x;
		var->player_y = new_y;
		var->moves++;
	}
	else if (var->map[new_y][new_x] == 'E')
	{
		var->moves++;
		ft_printf("%s", "You win\n");
		ft_close(var);
	}
}

void	render_map(t_vars *var)
{
	int	j;

	j = 0;
	while (var->map[j] != NULL)
	{
		ft_print(var->map[j], var, j);
		j++;
	}
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
		ft_close(var);
	else
		handle_keycode(keycode, var, &new_x, &new_y);
	update_map(var, new_x, new_y);
	ft_set_player(var, prev_x, prev_y);
	ft_printf("Moves: %d\n", var->moves);
	return (0);
}
