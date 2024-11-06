/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:26 by akiss             #+#    #+#             */
/*   Updated: 2024/11/03 19:15:17 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_images {
    void *img_floor;
    void *img_wall;
    void *img_ply;
    void *img_chest;
    void *img_exit;
    int img_width;
    int img_height;
} t_images;

typedef struct s_vars {
    void *mlx;
    void *win;
    char **map;
    int player_x;
    int player_y;
    int player_position_set;
    t_images images;
} t_vars;

void	ft_init_images(t_vars *vars);
void	ft_show_map (char *argv, t_vars *vars);
int	    ft_calc_height(char *argv);
int     ft_calc_height_map(char **map);
int	    ft_calc_width(char *argv);
void    ft_print(char *line, t_vars *vars, int j);
int     ft_check_map(char **map);

#endif