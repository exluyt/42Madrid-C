/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:34 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 16:42:04 by akiss            ###   ########.fr       */
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
	return (free(var->map), EXIT_SUCCESS);
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
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}

void	ft_initializes_mlx(t_vars *var, char *argv)
{
	var->width = ft_calc_width(argv);
	var->height = ft_calc_height(argv);
	var->mlx = mlx_init();
	if (!var->mlx)
		ft_close(var);
	ft_init_images(var);
	var->win = mlx_new_window(var->mlx, var->width * var->images.img_width,
			var->height * var->images.img_height, "so_long");
	if (!var->win)
		ft_close(var);
	var->player_position_set = 0;
}

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc != 2 || ft_strncmp(argv[1]
			+ ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (ft_printf("Error\nNot a valid extension (.ber)"), EXIT_FAILURE);
	else if (open(argv[1], O_RDONLY) < 0)
		return (perror(argv[1]), EXIT_FAILURE);
	else
	{
		ft_initializes_mlx(&var, argv[1]);
		var.map = malloc((var.height + 1) * sizeof(char *));
		if (!var.map)
			return (ft_close(&var), perror("Error\n"), EXIT_FAILURE);
		ft_show_map(argv[1], &var);
		if (ft_check_map(var.map, var) == EXIT_FAILURE)
			return (ft_printf("Error\nNot a valid map"),
				ft_close(&var), EXIT_FAILURE);
		var.moves = 0;
		mlx_hook(var.win, 2, 1L << 0, ft_esc, &var);
		mlx_hook(var.win, 17, 1L << 17, ft_close, &var);
		mlx_loop(var.mlx);
		ft_close(&var);
	}
	return (EXIT_SUCCESS);
}
