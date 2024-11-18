/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:34 by akiss             #+#    #+#             */
/*   Updated: 2024/11/18 11:11:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free_images(t_vars *vars)
{
    if (vars->images.img_wall)
        mlx_destroy_image(vars->mlx, vars->images.img_wall);
    if (vars->images.img_floor)
        mlx_destroy_image(vars->mlx, vars->images.img_floor);
    if (vars->images.img_ply)
        mlx_destroy_image(vars->mlx, vars->images.img_ply);
    if (vars->images.img_chest)
        mlx_destroy_image(vars->mlx, vars->images.img_chest);
    if (vars->images.img_exit)
        mlx_destroy_image(vars->mlx, vars->images.img_exit);
}

int ft_free_map(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->map[i] != NULL)
    {
        free(vars->map[i]);
        i++;
    }
    free(vars->map);
    return (0);
}

int ft_close(t_vars *vars)
{
    ft_free_map(vars);
    ft_free_images(vars);
    if (vars->win)
        mlx_destroy_window(vars->mlx, vars->win);
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
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
        if (vars->images.img_ply)
            mlx_destroy_image(vars->mlx, vars->images.img_ply);
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_u.xpm", &vars->images.img_width, &vars->images.img_height);
        new_y--;
    }
    else if (keycode == 115 || keycode == 65364)
    {
        if (vars->images.img_ply)
            mlx_destroy_image(vars->mlx, vars->images.img_ply);
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_d.xpm", &vars->images.img_width, &vars->images.img_height);
        new_y++;
    }
    else if (keycode == 97 || keycode == 65361)
    {
        if (vars->images.img_ply)
            mlx_destroy_image(vars->mlx, vars->images.img_ply);
        vars->images.img_ply = mlx_xpm_file_to_image(vars->mlx, "sprites/Player_l.xpm", &vars->images.img_width, &vars->images.img_height);
        new_x--;
    }
    else if (keycode == 100 || keycode == 65363)
    {
        if (vars->images.img_ply)
            mlx_destroy_image(vars->mlx, vars->images.img_ply);
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
    } else
    {
        int     width;
        int     height;
        t_vars  vars;

        width = ft_calc_width(argv[1]);
        height = ft_calc_height(argv[1]);
        vars.mlx = mlx_init();
        ft_init_images(&vars);
        if (!vars.mlx)
        {
            ft_close(&vars);
        }
        vars.win = mlx_new_window(vars.mlx, width * vars.images.img_width, height * vars.images.img_height, "so_long");
        if (!vars.win)
        {
            ft_close(&vars);
        }
        vars.player_position_set = 0;
        vars.map = malloc((height + 1) * sizeof(char *));
        if (!vars.map)
            ft_close(&vars);
        ft_show_map(argv[1], &vars);
        if(ft_check_map(vars.map))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        mlx_hook(vars.win, 2, 1L<<0, ft_esc, &vars);
        mlx_hook(vars.win, 17, 1L<<17, ft_close, &vars);
        mlx_loop(vars.mlx);
        ft_close(&vars);
    }
    return (0);
}