/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:34 by akiss             #+#    #+#             */
/*   Updated: 2024/11/19 12:52:44 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_images(t_vars *var)
{
	if (var->images.img_wall)
		mlx_destroy_image(var->mlx, var->images.img_wall);
	if (var->images.img_floor)
		mlx_destroy_image(var->mlx, var->images.img_floor);
	if (var->images.img_ply)
		mlx_destroy_image(var->mlx, var->images.img_ply);
	if (var->images.img_chest)
		mlx_destroy_image(var->mlx, var->images.img_chest);
	if (var->images.img_exit)
		mlx_destroy_image(var->mlx, var->images.img_exit);
}

int	ft_free_map(t_vars *var)
{
	int	i;

	i = 0;
	while (var->map[i] != NULL)
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
	return (0);
}

int	ft_close(t_vars *var)
{
	ft_free_map(var);
	ft_free_images(var);
	if (var->win)
		mlx_destroy_window(var->mlx, var->win);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
	exit(0);
	return (0);
}

void	ft_initializes_mlx(t_vars *var, int width, int height)
{
	var->mlx = mlx_init();
	if (!var->mlx)
		ft_close(var);
	ft_init_images(var);
	var->win = mlx_new_window(var->mlx, width * var->images.img_width,
			height * var->images.img_height, "so_long");
	if (!var->win)
		ft_close(var);
	var->player_position_set = 0;
}

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc != 2)
		return (0);
	else
	{
		var.width = ft_calc_width(argv[1]);
		var.height = ft_calc_height(argv[1]);
		ft_initializes_mlx(&var, var.width, var.height);
		var.map = malloc((var.height + 1) * sizeof(char *));
		if (!var.map)
			ft_close(&var);
		ft_show_map(argv[1], &var);
		if (ft_check_map(var.map, var) == EXIT_FAILURE)
			ft_close(&var);
		render_map(&var);
		var.moves = 0;
		mlx_hook(var.win, 2, 1L << 0, ft_esc, &var);
		mlx_hook(var.win, 17, 1L << 17, ft_close, &var);
		mlx_loop(var.mlx);
		ft_close(&var);
	}
	return (0);
}
