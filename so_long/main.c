/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:34 by akiss             #+#    #+#             */
/*   Updated: 2024/11/03 19:10:33 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
    return (0);
}

int ft_esc(int keycode, t_vars *vars)
{
    int new_x = vars->player_x;
    int new_y = vars->player_y;
    static int is_collected = 0;

    if (keycode == 65307)
        ft_close(vars);
    else if (keycode == 119 || keycode == 65362)
    {
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_u.xpm", &vars->images.img_width, &vars->images.img_height);
        new_y--;
    }
    else if (keycode == 115 || keycode == 65364)
    {
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_d.xpm", &vars->images.img_width, &vars->images.img_height);
        new_y++;
    }
    else if (keycode == 97 || keycode == 65361)
    {
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_l.xpm", &vars->images.img_width, &vars->images.img_height);
        new_x--;
    }
    else if (keycode == 100 || keycode == 65363)
    {
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_r.xpm", &vars->images.img_width, &vars->images.img_height);
        new_x++;
    }

    mlx_clear_window(vars->mlx, vars->win);

    if (vars->map[new_y][new_x] == '0')
    {
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->map[new_y][new_x] = 'P';
        vars->player_x = new_x;
        vars->player_y = new_y;
    }
    else if (vars->map[new_y][new_x] == 'C')
    {
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->map[new_y][new_x] = 'P';
        vars->player_x = new_x;
        vars->player_y = new_y;
        is_collected = 1;
    }
    else if (vars->map[new_y][new_x] == 'E' && is_collected == 1)
    {
        ft_printf("%s","You win\n");
        ft_close(vars);
    }

    int j = 0;
    while (vars->map[j] != NULL)
    {
        ft_print(vars->map[j], vars, j);
        j++;
    }

    return (0);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    } else {
        int width;
        int height;

        width = ft_calc_width(argv[1]);
        height = ft_calc_height(argv[1]);
        t_vars vars;
        vars.mlx = mlx_init();
        ft_init_images(&vars);
        vars.win = mlx_new_window(vars.mlx, width * vars.images.img_width, height * vars.images.img_height, "so_long");
        vars.player_position_set = 0;
        vars.map = malloc(sizeof(char *) * 100);
        ft_show_map(argv[1], &vars);
        if(ft_check_map(vars.map))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        mlx_hook(vars.win, 2, 1L<<0, ft_esc, &vars);
        mlx_hook(vars.win, 17, 1L<<17, ft_close, &vars);
        mlx_loop(vars.mlx);
    }
    return (0);
}